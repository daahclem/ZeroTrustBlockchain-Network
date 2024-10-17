simple DBA
{
    parameters:
        bool monitorActivity = default(true);
        string accessControlPolicy = default("strict");
        @display("i=device/server2");
    gates:
        input in;
        output out;
}
