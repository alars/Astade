//~~ void Initialize() [TickTackToeCapsule] ~~
aTrigger.m_tracefile = &Trace2UML::ms_ofile;
aTickTackToe.m_tracefile = &Trace2UML::ms_ofile;

//aTrigger.Initialize();
//aTickTackToe.Initialize();

AQF_MessageReceiver::staticSendMessage(&aTickTackToe,AQF_init);
AQF_MessageReceiver::staticSendMessage(&aTrigger,AQF_init);
