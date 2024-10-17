module DMZ {
    parameters:
        @display("i=block/cloud");

    gates:
        input dataIn;
        output dataOut;

    submodules:
        firewall: DMZFirewall {
            parameters:
                ruleSet = "default-rules";
            @display("p=100,100");
        }
        webServer: WebServer {
            @display("p=300,100");
        }
        applicationServer: ApplicationServer {
            @display("p=500,100");
        }

    connections:
        dataIn --> firewall.dataIn;
        firewall.dataOut --> webServer.dataIn;
        webServer.dataOut --> applicationServer.dataIn;
        applicationServer.dataOut --> dataOut;
}







