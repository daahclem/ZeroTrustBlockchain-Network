#include <omnetpp.h>

using namespace omnetpp;

class PassThrough : public cSimpleModule
{
protected:
    virtual void handleMessage(cMessage *msg) override {
        // Forward the incoming message to both outputs
        send(msg->dup(), "out1"); // Duplicate message for the first output
        send(msg, "out2"); // Original message to the second output
    }
};

Define_Module(PassThrough);
