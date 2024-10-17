simple Database
{
    parameters:
        bool isProtected = default(true);
        string accessPolicy = default("strict");
        @display("i=abstract/db;is=n");
    gates:
        input in;
        output out;
}
