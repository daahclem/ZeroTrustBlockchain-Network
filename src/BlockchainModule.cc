#include <omnetpp.h>
#include "CustomMessage_m.h"

using namespace omnetpp;

class BlockchainModule : public cSimpleModule {
protected:
    virtual void handleMessage(cMessage *msg) override {
        CustomMessage *custMsg = check_and_cast<CustomMessage *>(msg);
        EV << "Blockchain verifying message: " << custMsg->getContent() << endl;
        // Simulate blockchain verification
        if (verifyBlockchain(custMsg)) {
            send(custMsg, "out");
        } else {
            EV << "Blockchain verification failed for message: " << custMsg->getContent() << endl;
            delete custMsg;  // Delete message if verification fails
        }
    }

    bool verifyBlockchain(CustomMessage *msg) {
        // Simulate blockchain verification logic
        return true;  // Simplified for this example
    }
};

Define_Module(BlockchainModule);

