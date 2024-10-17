#include <omnetpp.h>

using namespace omnetpp;

class DummySink : public cSimpleModule {
protected:
    virtual void handleMessage(cMessage *msg) override {
        EV << "DummySink received a message: " << msg->getName() << " from " << msg->getSenderModule()->getFullPath() << endl;
        // Record some scalar values or vectors
               recordScalar("receivedMessages", 1);
        delete msg;
    }
};

Define_Module(DummySink);
