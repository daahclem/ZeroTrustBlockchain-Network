simple IDS {
    parameters:
        string detectionRules = default("detect-all");
    gates:
        input in;
        output out[2]; // Define the output gate vector with appropriate size
}








