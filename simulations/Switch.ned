simple Switch {
    parameters:
        int numPorts @prompt("Number of ports") = default(2); // Adjust the default number of ports
    gates:
        input portIn[numPorts];
        output portOut[numPorts];
}








