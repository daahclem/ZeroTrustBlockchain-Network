#include <omnetpp.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace omnetpp;

class HybridAccessControl : public cSimpleModule
{
  private:
    int packetCount; // To keep track of the number of processed packets

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(HybridAccessControl);

void HybridAccessControl::initialize()
{
    packetCount = 0; // Initialize packet count
}

void HybridAccessControl::handleMessage(cMessage *msg)
{
    EV << "HybridAccessControl: Received access request: " << msg->getName() << "\n";

    // Simulate RBAC, ABAC, DAC, and MAC policy evaluations
    EV << "Evaluating RBAC policy for request: " << msg->getName() << "\n";
    EV << "Evaluating ABAC policy for request: " << msg->getName() << "\n";
    EV << "Evaluating DAC policy for request: " << msg->getName() << "\n";
    EV << "Evaluating MAC policy for request: " << msg->getName() << "\n";
    EV << "Validating with blockchain for request: " << msg->getName() << "\n";

    // Determine access decision based on the packet count
    packetCount++;
    cMessage *responseMsg;

    if (packetCount % 2 == 1) {
        EV << "HybridAccessControl: Access granted\n";
        responseMsg = new cMessage("ACCESS_GRANTED");
    } else {
        EV << "HybridAccessControl: Access denied\n";
        responseMsg = new cMessage("ACCESS_DENIED");
    }

    // Forward the access decision
    send(responseMsg, "accessDecisionOut");
    delete msg;
}

