#include <omnetpp.h>

using namespace omnetpp;

class InternalFirewall : public cSimpleModule {
protected:
    virtual void initialize() override {
        // Initialization code here
    }

    virtual void handleMessage(cMessage *msg) override {
        // Forward the message to the appropriate output gate
        EV << "InternalFirewall received a message from: " << msg->getSenderModule()->getFullPath() << endl;
        send(msg, "out");
    }
};

Define_Module(InternalFirewall);
