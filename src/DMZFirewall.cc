#include <omnetpp.h>

using namespace omnetpp;

class DMZFirewall : public cSimpleModule {
private:
    std::string ruleSet;

protected:
    virtual void initialize() override {
        ruleSet = par("ruleSet").stdstringValue();
        EV << "DMZFirewall initialized with rules: " << ruleSet << "\n";
    }

    virtual void handleMessage(cMessage *msg) override {
        EV << "DMZFirewall received a message: " << msg->getName() << "\n";
        // For simplicity, allow all messages through the firewall
        send(msg, "dataOut");
    }
};

Define_Module(DMZFirewall);
