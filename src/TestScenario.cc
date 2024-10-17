#include <omnetpp.h>

using namespace omnetpp;

class TestScenario : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(TestScenario);

void TestScenario::initialize()
{
    // Create and send the initial CREDENTIALS message to the IdPModule
    cMessage *credMsg = new cMessage("CREDENTIALS");
    send(credMsg, "out");
}

void TestScenario::handleMessage(cMessage *msg)
{
    // Handle any incoming messages if needed
    delete msg;
}
