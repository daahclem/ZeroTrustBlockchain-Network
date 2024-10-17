// MFA.cc
#include "MFA.h"
#include <omnetpp.h>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace omnetpp;

Define_Module(MFA);

void MFA::initialize() {
    mfaType = par("mfaType").stringValue();
    std::srand(std::time(nullptr)); // Initialize random seed
}

void MFA::handleMessage(cMessage *msg) {
    EV << "MFA: Received message: " << msg->getName() << "\n";

    if (std::string(mfaType) == "OTP") {
        if (std::string(msg->getName()) == "REQUEST_OTP") {
            // Simulate OTP generation
            int otp = std::rand() % 10000; // Generate a 4-digit OTP
            EV << "MFA: Generated OTP: " << otp << "\n";

            // Store OTP for verification
            generatedOTP = otp;

            // Simulate sending OTP to user (
            // e.g., via SMS or email)
            cMessage *otpMsg = new cMessage("OTP_SENT");
            send(otpMsg, "mfaOut");
        } else if (std::string(msg->getName()) == "VERIFY_OTP") {
            // Simulate OTP verification
            int receivedOTP = msg->par("otp").longValue();
            EV << "MFA: Verifying OTP. Received: " << receivedOTP << ", Expected: " << generatedOTP << "\n";

            if (receivedOTP == generatedOTP) {
                EV << "MFA: OTP verification successful.\n";
                cMessage *mfaMsg = new cMessage("MFA_OK");
                send(mfaMsg, "mfaOut");
            } else {
                EV << "MFA: OTP verification failed.\n";
                cMessage *mfaMsg = new cMessage("MFA_FAIL");
                send(mfaMsg, "mfaOut");
            }
        }
    }
    delete msg;
}



