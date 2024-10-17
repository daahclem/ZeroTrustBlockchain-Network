#include <omnetpp.h>
using namespace omnetpp;

class DLPDatabase : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(DLPDatabase);

void DLPDatabase::initialize()
{
    // Initialization code, if any
}

void DLPDatabase::handleMessage(cMessage *msg)
{
    // Process incoming messages and forward them
    send(msg, "out");
}
