#include <omnetpp.h>

using namespace omnetpp;

class Switch : public cSimpleModule {
protected:
    virtual void initialize() override {
        // Initialization code here
    }

    virtual void handleMessage(cMessage *msg) override {
        // Forward the message to the appropriate output gate
        int outGateIndex = determineGateIndex(msg);
        EV << "Switch received a message and forwarding to gate index: " << outGateIndex << endl;
        send(msg, "portOut", outGateIndex);
    }

    int determineGateIndex(cMessage *msg) {
        // Determine the appropriate gate index based on the message or other criteria
        // For simplicity, this example forwards to gate index 0
        return 0; // Example logic, update as necessary
    }
};

Define_Module(Switch);

