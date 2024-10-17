simple ExternalFirewall {
    parameters:
        string ruleSet = default("default-deny");
    gates:
        input in[4]; // Adjust this number based on the number of distinct input connections required
        output out[2];
}









