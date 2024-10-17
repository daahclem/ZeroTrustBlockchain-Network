#include "PolicyEnforcementPoint.h"
#include <omnetpp.h>

using namespace omnetpp;

Define_Module(PolicyEnforcementPoint);

void PolicyEnforcementPoint::handleMessage(cMessage *msg) {
    if (strcmp(msg->getName(), "OTP_SENT") == 0 || strcmp(msg->getName(), "ACCESS_REQUEST") == 0) {
        EV << "PEP: Forwarding access request to PDP: " << msg->getName() << "\n";
        send(msg, "policyDecisionOut");
    } else if (strcmp(msg->getName(), "ACCESS_GRANTED") == 0 || strcmp(msg->getName(), "ACCESS_DENIED") == 0) {
        EV << "PEP: Enforcing access decision: " << msg->getName() << "\n";
        // Enforce the access decision from PDP
        send(msg, "accessOut");
    } else {
        delete msg;
    }
}





