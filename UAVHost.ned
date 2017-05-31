package uavsim;

import uavsim.uavnet.node.UAVModel.UAVBaseModel;
import inet.applications.contract.IPingApp;

module UAVHost extends UAVBaseModel
{
	parameters:
		int numPingTestApps = default(0);
		@display("i=device/quadcopter;");
		
	submodules:
	     pingTestApp[numPingTestApps]: <default("PingTestApp")> like IPingApp {
            parameters:
                @display("p=635,210,row,60");
        }
        
    connections allowunconnected:
		for i=0..numPingTestApps-1 {
            networkLayer.pingOut++ --> pingTestApp[i].pingIn;
            networkLayer.pingIn++ <-- pingTestApp[i].pingOut;
        }

}