//~~ void CodeEnterPointer() [StateChartCoderACFp] ~~

spec << "\t//! @brief The function pointer to the enter function of the next state." << std::endl;
spec << "\tbool ("
	<< myAdeStatechart->GetName().utf8_str()
	<< "::*nextState)("
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "*);\n"
	<< std::endl;

spec << "\t//! brief This is the enter function for state NoState (When the state chart terminates)." << std::endl;
spec << "\tbool Enter_NoState("
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "* theEvent);\n"
	<< std::endl;

impl << "bool "
	<< myAdeStatechart->GetName().utf8_str()
	<< "::Enter_NoState("
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "* theEvent)"
	<< std::endl;
impl << "{" << std::endl;

impl << "\t// Set the new state." << std::endl;
impl << "\ttheState = &"
	<< myAdeStatechart->GetName().utf8_str()
	<< "::NoState;"
	<< std::endl;

impl << "\t// call the virtual notify function" << std::endl;
impl << "\tnotifyNewState(\"NoState\");\n" << std::endl;

impl << "\tnextState = 0; // We stay in this state (for ever)" << std::endl;
impl << "\tterminate();" << std::endl;
impl << "\treturn false; // Don't continue handling this state chart" << std::endl;

impl << "}\n" << std::endl;
