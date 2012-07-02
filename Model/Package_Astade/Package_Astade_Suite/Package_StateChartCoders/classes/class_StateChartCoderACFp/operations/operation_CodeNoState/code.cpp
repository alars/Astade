//~~ void CodeNoState() [StateChartCoderACFp] ~~

spec << "\t//! @brief This is the default state before the state machine is initialized." << std::endl;
spec << "\t//! It does nothing. This makes sure that there is no crash if \"TakeEvent\" is called accidentally before \"Initialize\"." << std::endl;
spec << "\t//! @param theEvent The event to be processed." << std::endl;

spec << "\tbool NoState("
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "* theEvent);\n"
	<< std::endl;

impl << "bool "
	<< myAdeStatechart->GetName().utf8_str()
	<< "::NoState("
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "* theEvent)"
	<< std::endl;
impl << "{" << std::endl;
impl << "\treturn false;" << std::endl;
impl << "}\n" << std::endl;
