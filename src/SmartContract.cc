#include <omnetpp.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace omnetpp;

class SmartContract : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    void executeSmartContractFunction(const char *functionName, const char *param);
};

Define_Module(SmartContract);

void SmartContract::initialize()
{
    // Initialization code here
}

void SmartContract::handleMessage(cMessage *msg)
{
    EV << "SmartContract: Processing " << msg->getName() << "...\n";

    if (strcmp(msg->getName(), "ACCESS_GRANTED") == 0) {
        executeSmartContractFunction("record_outcome", "success");
        send(msg, "contractOut");
    } else if (strcmp(msg->getName(), "ACCESS_DENIED") == 0) {
        executeSmartContractFunction("record_outcome", "failure");
        delete msg; // Terminate the message if access is denied
    }
}

void SmartContract::executeSmartContractFunction(const char *functionName, const char *param)
{
    std::string cmd = "\"C:\\Program Files\\nodejs\\node.exe\" ";
    cmd += "C:\\Users\\donni\\Downloads\\omnetpp-6.0.2-windows-x86_64\\omnetpp-6.0.2\\samples\\NetworkSecurityModel\\src\\blockchain_interaction.js ";
    cmd += functionName;
    cmd += " ";
    cmd += "0xfba248a9906a38c0479fdd4e4446c2ddcf7933bb";
    cmd += " ";
    cmd += param;
    EV << "Executing command: " << cmd << "\n";
    int result = std::system(cmd.c_str());
    if (result == 0) {
        EV << "SmartContract: Successfully executed smart contract function\n";
    } else {
        EV << "SmartContract: Error executing smart contract function\n";
    }
}

