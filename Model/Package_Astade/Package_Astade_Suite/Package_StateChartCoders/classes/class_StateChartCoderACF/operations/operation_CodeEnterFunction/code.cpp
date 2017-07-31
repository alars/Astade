//~~ void CodeEnterFunction() [StateChartCoderACF] ~~

spec << "//! @brief This function calls the current enter Function until a stable state is reached." << std::endl;
spec << "//! @param me A pointer to the statechart instance." << std::endl;
spec << "//! @param theEvent The event passed to the actions and guards." << std::endl;
spec << "void "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_EnterState("
	<< myAdeStatechart->GetName().utf8_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "* theEvent);\n"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_EnterState("
	<< myAdeStatechart->GetName().utf8_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "* theEvent)"
	<< std::endl;
impl << "{" << std::endl;
impl << "\twhile (me->nextState)" << std::endl;
impl << "\t\t(me->nextState)(me, theEvent);" << std::endl;
impl << "}\n" << std::endl;
