simple BlockchainModule
{
    parameters:
        string blockchainNetworkName;
    gates:
        output out;
}

simple IdPModule
{
    parameters:
        string mfaToken;
    gates:
        input blockchainIn;
        input deviceIn;
        output idpOut;
}

simple MFA
{
    parameters:
        string mfaType = default("OTP"); // Default is OTP
    gates:
        input mfaIn;
        output mfaOut;
}

simple LogAnalysis
{
    gates:
        input logIn;
        output logOut;
}

simple PolicyEnforcementPoint
{
    gates:
        input accessRequestIn;
        output policyDecisionOut;
}

simple PolicyDecisionPoint
{
    gates:
        input policyRequestIn;
        output policyResponseOut;
}

simple HybridAccessControl
{
    parameters:
        string rbacPolicy;
        string abacPolicy;
        string dacPolicy;
        string macPolicy;
    gates:
        input accessRequestIn;
        output accessDecisionOut;
}

simple SecureChannelModule
{
    gates:
        input policyIn;
        output secureOut;
}

simple SmartContract
{
    parameters:
        string contractAddress;
        string contractABI;
    gates:
        input contractIn;
        output contractOut;
}

module IAMWithBlockchain {
    parameters:
        @display("p=1500,500");

    gates:
        input deviceIn;
        output secureOut;

    submodules:
        blockchain: BlockchainModule {
            parameters:
                blockchainNetworkName = "BankChain";
            @display("p=100,200");
        }
        idProvider: IdPModule {
            parameters:
                mfaToken = "defaultMFA";
            @display("p=300,200");
        }
        mfa: MFA {
            parameters:
                mfaType = "OTP";
            @display("p=500,200");
        }
        logAnalysis: LogAnalysis {
            @display("p=700,200");
        }
        policyEnforcementPoint: PolicyEnforcementPoint {
            @display("p=900,200");
        }
        policyDecisionPoint: PolicyDecisionPoint {
            @display("p=1100,200");
        }
        hybridAccessControl: HybridAccessControl {
            parameters:
                rbacPolicy = "defaultRBAC";
                abacPolicy = "defaultABAC";
                dacPolicy = "defaultDAC";
                macPolicy = "defaultMAC";
            @display("p=1300,200");
        }
        smartContract: SmartContract {
            parameters:
                contractAddress = "0xfba248a9906a38c0479fdd4e4446c2ddcf7933bb";
                contractABI = "[YOUR_CONTRACT_ABI]";
            @display("p=1500,200");
        }
        secureChannel: SecureChannelModule {
            @display("p=1700,200");
        }
    connections:
        // Authentication Flow
        blockchain.out --> idProvider.blockchainIn;
        idProvider.idpOut --> mfa.mfaIn;
        mfa.mfaOut --> logAnalysis.logIn;
        logAnalysis.logOut --> policyEnforcementPoint.accessRequestIn;

        // Authorization Flow
        policyEnforcementPoint.policyDecisionOut --> policyDecisionPoint.policyRequestIn;
        policyDecisionPoint.policyResponseOut --> hybridAccessControl.accessRequestIn;
        hybridAccessControl.accessDecisionOut --> smartContract.contractIn;
        smartContract.contractOut --> secureChannel.policyIn;

        // External Connections
        deviceIn --> idProvider.deviceIn;
        secureChannel.secureOut --> secureOut;
}
