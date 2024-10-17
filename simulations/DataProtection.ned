
simple DataClassification
{
    parameters:
        string classificationRules;
    gates:
        input dataIn;
        output dataOut;
}

simple DataLossPrevention
{
    parameters:
        string dlpRules;
    gates:
        input dataIn;
        output dataOut;
}

simple Encryption
{
    parameters:
        string encryptionKey;
    gates:
        input encryptIn;
        output encryptOut;
        input decryptIn;
        output decryptOut;
}

simple KeyManagementService
{
    gates:
        input keyRequestIn;
        output keyResponseOut;
}

simple EnterpriseSecurityManager
{
    parameters:
        string monitoringRules;
    gates:
        input monitorIn;
        output monitorOut;
}

module DataProtection
{
    parameters:
        @display("p=1000,500");

    gates:
        input dataIn;
        output dataOut;

    submodules:
        dataClassification: DataClassification {
            parameters:
                classificationRules = "default";
            @display("p=100,200");
        }
        dataLossPrevention: DataLossPrevention {
            parameters:
                dlpRules = "default";
            @display("p=300,200");
        }
        encryption: Encryption {
            parameters:
                encryptionKey = "defaultKey";
            @display("p=500,200");
        }
        keyManagementService: KeyManagementService {
            @display("p=700,200");
        }
        enterpriseSecurityManager: EnterpriseSecurityManager {
            parameters:
                monitoringRules = "default";
            @display("p=900,200");
        }

    connections:
        dataIn --> dataClassification.dataIn;
        dataClassification.dataOut --> dataLossPrevention.dataIn;
        dataLossPrevention.dataOut --> encryption.encryptIn;
        encryption.encryptOut --> enterpriseSecurityManager.monitorIn;
        enterpriseSecurityManager.monitorOut --> encryption.decryptIn;
        encryption.decryptOut --> dataOut;
}
