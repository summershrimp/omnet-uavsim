//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package uavsim;

import inet.common.lifecycle.LifecycleController;
import inet.common.scenario.ScenarioManager;
import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.physicallayer.ieee80211.packetlevel.*;
import inet.physicallayer.pathloss.*;
import inet.visualizer.integrated.IntegratedCanvasVisualizer;

network TestNetwork
{
    parameters:
        int numHosts;
        int numAttackHosts;
    submodules:
//		visualizer: IntegratedCanvasVisualizer {
// 			@display("p=580,125");
//  		}
        radioMedium: Ieee80211ScalarRadioMedium {
            parameters:
                @display("p=100,50");
        }
        configurator: IPv4NetworkConfigurator {
            parameters:
                config = xml("<config><interface hosts='*' address='192.168.1.x' netmask='255.255.255.0'/></config>");
                @display("p=100,100");
        }
        routingTableRecorder: RoutingTableRecorder {
            parameters:
                @display("p=100,150");
        }
        lifecycleController: LifecycleController {
            parameters:
                @display("p=100,200");
        }
        scenarioManager: ScenarioManager {
            parameters:
                script = default(xml("<scenario/>"));
                @display("p=100,250");
        }
        host[numHosts]: UAVHost {
            parameters:
                @display("p=360,200");
        }
        attackHost[numAttackHosts]: AttackHost {
            parameters:
                @display("p=360,100");
        }
    connections allowunconnected:
}
