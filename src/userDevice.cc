#include <omnetpp.h>

using namespace omnetpp;

class userDevice : public cSimpleModule {
  private:
    cMessage *sendMessageEvent; // Pointer to the event object which we'll use for timing
    simtime_t sendInterval;     // Interval between messages

  public:
    userDevice();
    virtual ~userDevice();

  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
    virtual void sendPacket();
};

Define_Module(userDevice);

userDevice::userDevice() {
    sendMessageEvent = nullptr;
}

userDevice::~userDevice() {
    cancelAndDelete(sendMessageEvent);
}

void userDevice::initialize() {
    sendMessageEvent = new cMessage("sendMessageEvent");
    sendInterval = par("sendInterval");
    scheduleAt(simTime() + sendInterval, sendMessageEvent);
}

void userDevice::handleMessage(cMessage *msg) {
    if (msg == sendMessageEvent) {
        sendPacket();
        scheduleAt(simTime() + sendInterval, sendMessageEvent);
    }
}

void userDevice::sendPacket() {
    cMessage *packet = new cMessage("packet");
    send(packet, "out");
}
