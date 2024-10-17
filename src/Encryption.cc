#include <omnetpp.h>

using namespace omnetpp;

class Encryption : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(Encryption);

void Encryption::initialize()
{
    // Initialization code here
}

void Encryption::handleMessage(cMessage *msg)
{
    // Determine whether to encrypt or decrypt based on gate
    if (msg->arrivedOn("encryptIn"))
    {
        // Encrypt the message
        EV << "Encrypting data" << endl;
        send(msg, "encryptOut");
    }
    else if (msg->arrivedOn("decryptIn"))
    {
        // Decrypt the message
        EV << "Decrypting data" << endl;
        send(msg, "decryptOut");
    }
}


