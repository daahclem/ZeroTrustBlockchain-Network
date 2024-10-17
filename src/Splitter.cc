#include <omnetpp.h>

using namespace omnetpp;

class Splitter : public cSimpleModule
{
  protected:
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Splitter);

void Splitter::handleMessage(cMessage *msg)
{
    // Forward the message to all output gates
    for (int i = 0; i < gateSize("out"); ++i) {
        send(msg->dup(), "out", i);
    }
    delete msg;
}
