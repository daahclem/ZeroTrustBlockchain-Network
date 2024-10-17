#include <omnetpp.h>

using namespace omnetpp;

class NetworkMonitor : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(NetworkMonitor);

void NetworkMonitor::initialize()
{
    // Initialization code here
}

void NetworkMonitor::handleMessage(cMessage *msg)
{
    // Process incoming message
    EV << "Received message: " << msg->getName() << "\n";
    // Perform analysis or logging

    // Optionally, forward the message or delete it
    delete msg;
}
