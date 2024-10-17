simple DDoSAttacker {
    parameters:
        double attackInterval @unit(s) = default(0.1s); // Interval between sending attack packets
    gates:
        output out;
}

