//~~ void CodeNoState() [StateChartCoderQt] ~~

spec << "\t//! @brief This is the default state before the state machine is initialized." << std::endl;
spec << "\t//! It does nothing. This makes sure that there is no crash if \"TakeEvent\" is called accidentally before \"Initialize\"." << std::endl;
spec << "\t//! @param port The machine that send the event." << std::endl;
spec << "\t//! @param theEvent The event to be processed." << std::endl;

spec << "\tvoid NoState(const AQF_MessageReceiver* port, const "
    << myAdeStatechart->GetEventType().utf8_str()
    << "& theEvent);\n"
    << std::endl;

impl << "void "
    << myAdeStatechart->GetName().utf8_str()
    << "::NoState(const AQF_MessageReceiver* port, const "
    << myAdeStatechart->GetEventType().utf8_str()
    << "& theEvent)"
    << std::endl;
impl << "{" << std::endl;
impl << "\tQ_UNUSED(port);" << std::endl;
impl << "\tQ_UNUSED(theEvent);" << std::endl;

std::list<wxString> aList = myAdeStatechart->GetInitialActions();

impl << "\tif (theEvent.getID() == AQF_init)" << std::endl;
impl << "\t{" << std::endl;

impl << "\t\t// Calling the initial actions" << std::endl;

for (std::list<wxString>::iterator iter = aList.begin(); iter != aList.end(); ++iter)
    impl << "\t\t"
        << iter->utf8_str()
        << "(0, AQF_Message());"
        << std::endl;

impl << "\t\t// Set the initial State function" << std::endl;
impl << "\t\tnextState = &"
     << myAdeStatechart->GetName().utf8_str()
     << "::Enter_"
     << myAdeStatechart->GetInitialState().utf8_str()
     << ";"
     << std::endl;

impl << "\t}\n}\n" << std::endl;
