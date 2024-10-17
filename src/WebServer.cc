#include <omnetpp.h>

using namespace omnetpp;

class WebServer : public cSimpleModule {
protected:
    virtual void initialize() override {
        EV << "WebServer initialized.\n";
    }

    virtual void handleMessage(cMessage *msg) override {
        EV << "WebServer received a message: " << msg->getName() << "\n";
        send(msg, "dataOut");
    }
};

Define_Module(WebServer);

