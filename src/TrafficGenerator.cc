#include <omnetpp.h>

using namespace omnetpp;

class TrafficGenerator : public cSimpleModule {
  private:
    cMessage *sendMessageEvent; // Pointer to the event object which we'll use for timing
    simtime_t sendInterval;     // Interval between messages

  public:
    TrafficGenerator();
    virtual ~TrafficGenerator();

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void sendPacket();
};

Define_Module(TrafficGenerator);

TrafficGenerator::TrafficGenerator() {
    sendMessageEvent = nullptr;
}

TrafficGenerator::~TrafficGenerator() {
    cancelAndDelete(sendMessageEvent);
}

void TrafficGenerator::initialize() {
    sendMessageEvent = new cMessage("sendMessageEvent");
    sendInterval = par("sendInterval");
    scheduleAt(simTime() + sendInterval, sendMessageEvent);
}

void TrafficGenerator::handleMessage(cMessage *msg) {
    if (msg == sendMessageEvent) {
        sendPacket();
        scheduleAt(simTime() + sendInterval, sendMessageEvent);
    }
}

void TrafficGenerator::sendPacket() {
    cMessage *packet = new cMessage("packet");
    send(packet, "out");
}
