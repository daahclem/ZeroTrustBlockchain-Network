// IdPModule.h
#ifndef IDPMODULE_H
#define IDPMODULE_H

#include <omnetpp.h>

using namespace omnetpp;

class IdPModule : public cSimpleModule {
  private:
    const char *mfaToken;

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
};

#endif

