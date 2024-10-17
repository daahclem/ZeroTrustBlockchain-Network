// MFA.h
#ifndef MFA_H
#define MFA_H

#include <omnetpp.h>

using namespace omnetpp;

class MFA : public cSimpleModule {
  private:
    const char *mfaType;
    int generatedOTP;

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif
