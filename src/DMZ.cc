#include <omnetpp.h>

using namespace omnetpp;

class DMZ : public cSimpleModule {
protected:
    virtual void initialize() override {
        // Initialization code here
        EV << "DMZ initialized.\n";
    }

    virtual void handleMessage(cMessage *msg) override {
        // Handle incoming message
        EV << "DMZ received a message: " << msg->getName() << "\n";
        send(msg, "dataOut");
    }
};

Define_Module(DMZ);


