simple DMZFirewall {
    parameters:
        string ruleSet;
    gates:
        input dataIn;
        output dataOut;
}