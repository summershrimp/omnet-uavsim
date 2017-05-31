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

package uavsim.uavnet.node.UAVModel;

import inet.node.inet.WirelessHost;
import uavsim.uavnet.networklayer.contract.IManetRouting;

module UAVBaseModel extends WirelessHost
{
    parameters:
        @display("i=device/drone");
        wlan[*].mgmtType = default("Ieee80211MgmtAdhoc");  // use adhoc management
        string routingProtocol @enum("AODVUU","DYMOUM","DYMO","DSRUU","OLSR","OLSR_ETX","DSDV_2","Batman") = default(""); 
        forwarding = default(true);

    submodules:
        manetrouting: <routingProtocol> like IManetRouting if routingProtocol != "" {
            @display("p=522,307");
        }
    connections:
        networkLayer.transportOut++ --> manetrouting.ipIn if routingProtocol != "";
        networkLayer.transportIn++ <-- manetrouting.ipOut if routingProtocol != "";
}