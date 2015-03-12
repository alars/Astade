//~~ void CodeNoState() [StateChartCoderQt] ~~

spec << "\t//! @brief This is the default state before the state machine is initialized." << std::endl;
spec << "\t//! It does nothing. This makes sure that there is no crash if \"TakeEvent\" is called accidentally before \"Initialize\"." << std::endl;
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
impl << "}\n" << std::endl;
