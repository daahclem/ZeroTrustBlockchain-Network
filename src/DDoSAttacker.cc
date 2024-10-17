#include <omnetpp.h>

using namespace omnetpp;

class DDoSAttacker : public cSimpleModule {
  private:
    cMessage *attackTimer;
    simtime_t attackInterval;

  protected:
    virtual void initialize() override {
        //attackInterval = par("attackInterval");
        //attackTimer = new cMessage("attackTimer");
        //scheduleAt(simTime() + attackInterval, attackTimer);
    }

    virtual void handleMessage(cMessage *msg) override {
        if (msg == attackTimer) {
            //cPacket *pkt = new cPacket("DDoS Attack Packet");
            //send(pkt, "out");
            //scheduleAt(simTime() + attackInterval, attackTimer);
        }
    }

    virtual void finish() override {
        cancelAndDelete(attackTimer);
    }
};

Define_Module(DDoSAttacker);
