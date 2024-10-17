simple Endpoint {
    parameters:
        bool isProtected = default(true); // Whether the endpoint has malware protection
        string accessPolicy = default("strict"); // Define access policies under Zero Trust
    gates:
        input in;
         output out;
}



