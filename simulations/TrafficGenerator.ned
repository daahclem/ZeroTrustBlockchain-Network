simple TrafficGenerator {
    parameters:
        double sendInterval @unit(s) = default(1s); // Interval between sending messages
    gates:
        output out;
}

