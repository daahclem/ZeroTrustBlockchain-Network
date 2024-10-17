#include <string.h>
#include <vector>
#include <omnetpp.h>

using namespace omnetpp;

class ExternalFirewall : public cSimpleModule {
private:
    std::vector<std::string> allowedSources;

protected:
    virtual void initialize() override {
        // Initialize rules from parameters, always allow IAMWithBlockchain.secureChannel
        allowedSources.push_back("NetworkSecurityModel.IAMWithBlockchain.secureChannel"); // Explicitly allow IAMWithBlockchain.secureChannel
        parseRuleSet(par("ruleSet").stdstringValue());
    }

    virtual void handleMessage(cMessage *msg) override {
        std::string srcFullPath = msg->getSenderModule()->getFullPath();
        const char* srcFullPathCStr = srcFullPath.c_str();
        EV << "Received a message from: " << srcFullPathCStr << endl;
        if (isAllowed(srcFullPathCStr)) {
            EV << "Firewall allows the message from: " << srcFullPathCStr << endl;
            send(msg, "out", determineGateIndex(msg));
        } else {
            EV << "Firewall blocked a message from an unauthorized source: " << srcFullPathCStr << endl;
            delete msg;
        }
    }

    void parseRuleSet(std::string rules) {
        size_t pos = 0;
        std::string token;
        while ((pos = rules.find(';')) != std::string::npos) {
            token = rules.substr(0, pos);
            token = token.substr(token.find("from ") + 5); // Extract the source
            EV << "Parsed allowed source: " << token << endl;
            allowedSources.push_back(token);
            rules.erase(0, pos + 1);
        }
        token = rules.substr(rules.find("from ") + 5); // Add last or only item
        EV << "Parsed allowed source: " << token << endl;
        allowedSources.push_back(token);
    }

    bool isAllowed(const char* src) {
        EV << "Checking if message from " << src << " is allowed." << endl;
        for (const auto& allowedSrc : allowedSources) {
            EV << "Comparing against allowed source: " << allowedSrc << endl;
            if (strcmp(src, allowedSrc.c_str()) == 0) {
                return true;
            }
        }
        return false;
    }

    int determineGateIndex(cMessage *msg) {
        // Determine the appropriate gate index based on the message or other criteria
        // This is a placeholder function, you may need to update it to match your logic
        if (msg->getKind() == 0) {
            return 0; // Example logic, update as necessary
        } else {
            return 1; // Example logic, update as necessary
        }
    }
};

Define_Module(ExternalFirewall);
