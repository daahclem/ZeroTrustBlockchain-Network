#include <omnetpp.h>
#include <list>
#include <string>

using namespace omnetpp;

class Database : public cSimpleModule {
private:
    std::list<cMessage*> storedMessages;
    std::string key = "simplekey"; // Simple key for XOR decryption

protected:
    virtual void initialize() override {
        // Initialization code here
    }

    virtual void handleMessage(cMessage *msg) override {
        // Decrypt the message if encrypted
        if (msg->hasPar("isEncrypted") && msg->par("isEncrypted").boolValue()) {
            decryptData(msg);
        }

        // Simulate storing the message in the database
        EV << "Database received and storing message: " << msg->getName() << endl;
        storedMessages.push_back(msg->dup()); // Store a copy of the message

        // Forward a copy of the message to the Vulnerability Scanner
        cMessage *copyMsg = msg->dup();
        send(copyMsg, "out");

        // Optionally, delete the original message if not needed
        delete msg;
    }

    virtual void finish() override {
        // Clean up stored messages
        for (cMessage *msg : storedMessages) {
            delete msg;
        }
        storedMessages.clear();
    }

    void decryptData(cMessage *msg) {
        // XOR Decryption logic (same as encryption due to XOR properties)
        std::string ciphertext = msg->par("encryptedData").stringValue();
        std::string decryptedtext = ciphertext;

        for (size_t i = 0; i < ciphertext.size(); ++i) {
            decryptedtext[i] = ciphertext[i] ^ key[i % key.size()];
        }

        msg->setName(decryptedtext.c_str());
        msg->par("isEncrypted") = false;
        EV << "Encrypted data: " << ciphertext << "\n";
        EV << "Decrypted data: " << decryptedtext << "\n";
        EV << "Data decrypted\n";
    }
};

Define_Module(Database);
