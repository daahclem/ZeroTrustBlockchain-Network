// PolicyDecisionPoint.h
#ifndef POLICYDECISIONPOINT_H
#define POLICYDECISIONPOINT_H

#include <omnetpp.h>

using namespace omnetpp;

class PolicyDecisionPoint : public cSimpleModule {
  protected:
    virtual void handleMessage(cMessage *msg);
};

#endif
