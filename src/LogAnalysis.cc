#include <omnetpp.h>
#include <fstream>

using namespace omnetpp;

class LogAnalysis : public cSimpleModule
{
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg) override;
};

Define_Module(LogAnalysis);

void LogAnalysis::initialize()
{
    // Initialization code here
}

void LogAnalysis::handleMessage(cMessage *msg)
{
    EV << "LogAnalysis: Analyzing log: " << msg->getName() << "\n";

    // Simulate log analysis
    std::ofstream logFile("log_analysis_results.txt", std::ios_base::app);
    logFile << "Log entry: " << msg->getName() << "\n";
    logFile.close();

    // Forward the message
    send(msg, "logOut");
}


