// PolicyEnforcementPoint.h
#ifndef POLICYENFORCEMENTPOINT_H
#define POLICYENFORCEMENTPOINT_H

#include <omnetpp.h>

using namespace omnetpp;

class PolicyEnforcementPoint : public cSimpleModule {
  protected:
    virtual void handleMessage(cMessage *msg);
};

#endif
