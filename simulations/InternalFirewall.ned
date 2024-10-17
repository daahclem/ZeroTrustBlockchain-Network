simple InternalFirewall {
    parameters:
        string ruleSet = default("allow-none"); // Start with the strictest policy: deny all unless explicitly allowed
    gates:
        input in;
        output out;
}
