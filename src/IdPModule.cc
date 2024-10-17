#include "IdPModule.h"
#include <omnetpp.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace omnetpp;

Define_Module(IdPModule);

void IdPModule::initialize() {
    mfaToken = par("mfaToken").stringValue();
}

void IdPModule::handleMessage(cMessage *msg) {
    EV << "IdPModule: Received message: " << msg->getName() << "\n";

    // Handle incoming credential verification request
    if (strcmp(msg->getName(), "packet") == 0) {
        EV << "IdPModule: Verifying credentials...\n";
        bool credentialsVerified = false; // Assume credentials are not verified initially

        // Construct the full path to blockchain_interaction.js
        std::string cmd = "\"C:\\Program Files\\nodejs\\node.exe\" ";
        cmd += "C:\\Users\\donni\\Downloads\\omnetpp-6.0.2-windows-x86_64\\omnetpp-6.0.2\\samples\\NetworkSecurityModel\\src\\blockchain_interaction.js verify_credentials 0xfba248a9906a38c0479fdd4e4446c2ddcf7933bb actual_dynamic_credentials";
        EV << "Executing command: " << cmd << "\n";
        int result = std::system(cmd.c_str());
        EV << "Blockchain verification result: " << result << "\n";

        credentialsVerified = (result == 0); // Assume 0 means success

        if (credentialsVerified) {
            EV << "IdPModule: Credentials verified. Requesting OTP...\n";
            cMessage *otpRequest = new cMessage("REQUEST_OTP");
            send(otpRequest, "idpOut");

            // Record outcome on blockchain
            cmd = "\"C:\\Program Files\\nodejs\\node.exe\" ";
            cmd += "C:\\Users\\donni\\Downloads\\omnetpp-6.0.2-windows-x86_64\\omnetpp-6.0.2\\samples\\NetworkSecurityModel\\src\\blockchain_interaction.js record_outcome 0xfba248a9906a38c0479fdd4e4446c2ddcf7933bb success";
            EV << "Executing command: " << cmd << "\n";
            std::system(cmd.c_str());
        } else {
            EV << "IdPModule: Blockchain credentials verification failed.\n";
            cMessage *failureMsg = new cMessage("CREDENTIALS_FAIL");
            send(failureMsg, "idpOut");

            // Record outcome on blockchain
            cmd = "\"C:\\Program Files\\nodejs\\node.exe\" ";
            cmd += "C:\\Users\\donni\\Downloads\\omnetpp-6.0.2-windows-x86_64\\omnetpp-6.0.2\\samples\\NetworkSecurityModel\\src\\blockchain_interaction.js record_outcome 0xfba248a9906a38c0479fdd4e4446c2ddcf7933bb failure";
            EV << "Executing command: " << cmd << "\n";
            std::system(cmd.c_str());
        }
    } else if (strcmp(msg->getName(), "OTP_SENT") == 0) {
        EV << "IdPModule: OTP sent to user. Waiting for verification...\n";
        // Simulate user entering OTP
        int userOTP = 1234; // Example OTP entered by the user
        cMessage *otpVerify = new cMessage("VERIFY_OTP");
        otpVerify->addPar("otp").setLongValue(userOTP);
        send(otpVerify, "idpOut");
    } else if (strcmp(msg->getName(), "MFA_OK") == 0) {
        EV << "IdPModule: MFA verification successful. Proceeding...\n";
        cMessage *mfaSuccess = new cMessage("MFA_OK");
        send(mfaSuccess, "idpOut");
    } else if (strcmp(msg->getName(), "MFA_FAIL") == 0) {
        EV << "IdPModule: MFA verification failed.\n";
        cMessage *mfaFail = new cMessage("MFA_FAIL");
        send(mfaFail, "idpOut");
    }
    delete msg;
}
