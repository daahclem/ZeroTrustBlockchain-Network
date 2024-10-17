#include "PolicyDecisionPoint.h"
#include <omnetpp.h>

using namespace omnetpp;

Define_Module(PolicyDecisionPoint);

void PolicyDecisionPoint::handleMessage(cMessage *msg) {
    EV << "PDP: Received policy request: " << msg->getName() << "\n";

    // Forward the policy request to HybridAccessControl for evaluation
    cMessage *policyRequest = new cMessage("POLICY_REQUEST");
    send(policyRequest, "policyResponseOut");
    delete msg;
}




