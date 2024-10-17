#include <omnetpp.h>
#include <string>
#include <ctime>
#include <sstream>

using namespace omnetpp;

class Endpoint : public cSimpleModule {
protected:
    virtual void initialize() override {
        // Initialization code here
        EV << "Endpoint initialized\n";
    }

    virtual void handleMessage(cMessage *msg) override {
        if (msg->isSelfMessage()) {
            // Self-message handling, assume processing is done
            EV << "Endpoint completed processing message: " << msg->getName() << endl;

            // Optionally respond to the message
            if (shouldRespond()) {
                respondToMessage(msg);
            } else {
                // Forward the message to the appropriate output gate
                EV << "Endpoint forwarding the message: " << msg->getName() << endl;
                send(msg, "out");
            }
        } else {
            // Received message from another module
            EV << "Endpoint received a message from: " << msg->getSenderModule()->getFullPath() << endl;

            // Simulate processing the received message
            processMessage(msg);
        }
    }

    void processMessage(cMessage *msg) {
        // Simulate some processing delay
        simtime_t processingTime = uniform(0.01, 0.1);

        // Clone the message before scheduling it as a self-message
        cMessage *selfMsg = msg->dup();
        scheduleAt(simTime() + processingTime, selfMsg);
        EV << "Processing message: " << msg->getName() << " for " << processingTime << " seconds\n";

        // Delete the original message if not needed
        delete msg;
    }

    void logMessage(cMessage *msg) {
        // Log the received message with a timestamp
        std::time_t currentTime = std::time(nullptr);
        std::stringstream ss;
        ss << "Received message: " << msg->getName()
           << " from " << msg->getSenderModule()->getFullPath()
           << " at " << std::ctime(&currentTime);
        EV << ss.str();
    }

    bool shouldRespond() {
        // Randomly decide whether to respond to the message
        return uniform(0, 1) < 0.5;
    }

    void respondToMessage(cMessage *msg) {
        // Create a response message
        std::string responseName = std::string("responseTo_") + msg->getName();
        cMessage *response = new cMessage(responseName.c_str());

        // Send the response back to the sender
        EV << "Endpoint responding to the message: " << msg->getName() << " with " << responseName << endl;
        send(response, "out");
    }
};

Define_Module(Endpoint);




