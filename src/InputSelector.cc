#include <omnetpp.h>

using namespace omnetpp;

class InputSelector : public cSimpleModule {
protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(InputSelector);

void InputSelector::initialize() {
    // Initialization logic
}

void InputSelector::handleMessage(cMessage *msg) {
    // Example: Simply pass the message to the next component
    if (gate("out")->isConnected()) {
        send(msg, "out");
    } else {
        EV << "Output gate is not connected." << endl;
        delete msg;
    }
}
