
network NetworkSecurityModel
{
    @display("bgb=3200.4075,1222.3463"); // Adjust display settings as needed

    submodules:
        userDevice: userDevice {
            parameters:
                sendInterval = 1s;
                @display("p=2829.379,505.3275;i=device/wifilaptop");
        }
        externalFirewall: ExternalFirewall {
            parameters:
                ruleSet = "default-deny; allow from 192.168.1.0/24";
                @display("p=2251.2114,118.365005;i=device/firewall");
        }
        internet: Internet {
            @display("p=2633.6213,25.03875;i=misc/cloud");
        }
        dmz: DMZ {
            @display("p=1852.8676,161.61375;i=misc/building");
        }
        ids: IDS {
            parameters:
                detectionRules = "detect-all";
                @display("p=1809.6188,373.30502;i=block/wrxtx");
        }
        financeSwitch: Switch {
            parameters:
                numPorts = 1;
                @display("p=1554.6788,462.07877;i=abstract/switch");
        }
        creditCardSwitch: Switch {
            parameters:
                numPorts = 1;
                @display("p=1643.4525,70.56375;i=abstract/switch");
        }
        financeInternalFirewall: InternalFirewall {
            parameters:
                ruleSet = "default-deny; allow from 10.1.0.0/16";
                @display("p=1283.805,421.10626;i=device/firewall");
        }
        creditCardInternalFirewall: InternalFirewall {
            parameters:
                ruleSet = "default-deny; allow from 10.2.0.0/16";
                @display("p=1283.805,102.43125;i=device/firewall");
        }
        financeEndpoint: Endpoint {
            parameters:
                isProtected = true;
                accessPolicy = "strict";
                @display("p=1103.9813,616.8638;i=old/redbox");
        }
        creditCardEndpoint: Endpoint {
            parameters:
                isProtected = true;
                accessPolicy = "strict";
                @display("p=910.5,229.90126;i=old/redbox");
        }
        financeDatabase: Database {
            parameters:
                isProtected = true;
                accessPolicy = "strict";
                @display("p=830.8313,564.51");
        }
        creditCardDatabase: Database {
            parameters:
                isProtected = true;
                accessPolicy = "strict";
                @display("p=762.54376,70.56375");
        }
        financeDBA: DBA {
            parameters:
                monitorActivity = true;
                accessControlPolicy = "hybrid";
                @display("p=571.33875,564.51");
        }
        creditCardDBA: DBA {
            parameters:
                monitorActivity = true;
                accessControlPolicy = "hybrid";
                @display("p=569.0625,279.97876");
        }
        financeVulnerabilityScanner: VulnerabilityScanner {
            parameters:
                tool = "Nessus";
                scanInterval = 60s;
                @display("p=307.29376,373.30502;i=device/scanner");
        }
        creditCardVulnerabilityScanner: VulnerabilityScanner {
            parameters:
                tool = "OpenVAS";
                scanInterval = 60s;
                @display("p=396.0675,104.707504;i=device/scanner");
        }
        financeDummySink: DummySink {
            @display("p=116.08875,701.085;i=old/sink");
        }
        creditCardDummySink: DummySink {
            @display("p=61.45875,70.56375;i=old/sink");
        }
        ddosAttacker[2]: DDoSAttacker {
            @display("p=2797.5112,254.94;i=misc/person3");
        }
        IAMWithBlockchain: IAMWithBlockchain {
            @display("p=2214.7913,423.3825");
        }

    connections:
        userDevice.out --> IAMWithBlockchain.deviceIn;
        IAMWithBlockchain.secureOut --> externalFirewall.in[0];
        ddosAttacker[0].out --> externalFirewall.in[1];
        ddosAttacker[1].out --> externalFirewall.in[2];
        internet.out --> externalFirewall.in[3];

        externalFirewall.out[0] --> dmz.dataIn;
        dmz.dataOut --> ids.in;
        ids.out[0] --> financeSwitch.portIn[0];
        ids.out[1] --> creditCardSwitch.portIn[0];

        financeSwitch.portOut[0] --> financeInternalFirewall.in;
        creditCardSwitch.portOut[0] --> creditCardInternalFirewall.in;

        financeInternalFirewall.out --> financeEndpoint.in;
        creditCardInternalFirewall.out --> creditCardEndpoint.in;

        financeEndpoint.out --> financeDatabase.in;
        creditCardEndpoint.out --> creditCardDatabase.in;

        financeDatabase.out --> financeDBA.in;
        creditCardDatabase.out --> creditCardDBA.in;

        financeDBA.out --> financeVulnerabilityScanner.in;
        creditCardDBA.out --> creditCardVulnerabilityScanner.in;

        financeVulnerabilityScanner.out --> financeDummySink.in;
        creditCardVulnerabilityScanner.out --> creditCardDummySink.in;

        externalFirewall.out[1] --> internet.in;
}
