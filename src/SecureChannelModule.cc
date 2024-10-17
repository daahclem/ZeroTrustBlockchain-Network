#include <omnetpp.h>
#include <string>
#include <sstream>

using namespace omnetpp;

class SecureChannelModule : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    void classifyData(cMessage *msg);
    void encryptData(cMessage *msg);
    void decryptData(cMessage *msg);
    void performDLP(cMessage *msg);

    std::string key = "simplekey"; // Simple key for XOR encryption
};

Define_Module(SecureChannelModule);

void SecureChannelModule::initialize()
{
    // Initialization code here
}

void SecureChannelModule::handleMessage(cMessage *msg)
{
    EV << "SecureChannelModule: Received message: " << msg->getName() << "\n";

    classifyData(msg);
    performDLP(msg);
}

void SecureChannelModule::classifyData(cMessage *msg)
{
    // Data classification logic
    // For the sake of the example, we assume all data is classified as "Confidential"
    msg->addPar("classification") = "Confidential"; // Change this for testing
    EV << "Data classified as Confidential\n";
}

void SecureChannelModule::performDLP(cMessage *msg)
{
    // Data Loss Prevention logic based on classification
    std::string classification = msg->par("classification").stringValue();
    if (classification == "Confidential") {
        EV << "Data classification: " << classification << "\n";
        encryptData(msg);
        EV << "Data encrypted and allowed\n";
        send(msg, "secureOut");
    } else if (classification == "Non Business") {
        EV << "Data blocked and returned\n";
        delete msg; // Data blocked
    } else {
        EV << "Data allowed without encryption\n";
        send(msg, "secureOut");
    }
}

void SecureChannelModule::encryptData(cMessage *msg)
{
    // XOR Encryption logic
    std::string plaintext = msg->getName();
    std::string ciphertext = plaintext;

    for (size_t i = 0; i < plaintext.size(); ++i) {
        ciphertext[i] = plaintext[i] ^ key[i % key.size()];
    }

    msg->addPar("encryptedData") = ciphertext.c_str(); // Convert to const char*
    msg->addPar("isEncrypted") = true;
    EV << "Original data: " << plaintext << "\n";
    EV << "Encrypted data: " << ciphertext << "\n";
    EV << "Data encrypted\n";
}

void SecureChannelModule::decryptData(cMessage *msg)
{
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
