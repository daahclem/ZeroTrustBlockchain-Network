#include <omnetpp.h>

using namespace omnetpp;

class ApplicationServer : public cSimpleModule {
protected:
    virtual void initialize() override {
        EV << "ApplicationServer initialized.\n";
    }

    virtual void handleMessage(cMessage *msg) override {
        EV << "ApplicationServer received a message: " << msg->getName() << "\n";
        send(msg, "dataOut");
    }
};

Define_Module(ApplicationServer);

