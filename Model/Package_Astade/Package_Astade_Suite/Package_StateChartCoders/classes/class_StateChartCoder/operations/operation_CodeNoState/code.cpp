//~~ void CodeNoState() [StateChartCoder] ~~
spec << "\t//! @brief This is the default state before the state machine is initialized." << std::endl;
spec << "\t//! It does nothing. This makes sure that there is no crash if \"TakeEvent\" is called accidentally before \"Initialize\"." << std::endl;

spec << "\tbool NoState("
	<< myAdeStatechart->GetEventType().c_str()
	<< "& theEvent, eventIDs itsID);\n"
	<< std::endl;

impl << "bool "
	<< myAdeStatechart->GetName().c_str()
	<< "::NoState("
	<< myAdeStatechart->GetEventType().c_str()
	<< "& theEvent, eventIDs itsID)"
	<< std::endl;
impl << "{" << std::endl;
impl << "\treturn false;" << std::endl;
impl << "}\n" << std::endl;
