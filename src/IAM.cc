#include <omnetpp.h>

using namespace omnetpp;

class IAM : public cSimpleModule
{
protected:
    virtual void handleMessage(cMessage *msg) override {
        // Perform authentication, possibly requiring MFA
        // This example assumes successful authentication
        send(msg, "out");
    }
};

Define_Module(IAM);
