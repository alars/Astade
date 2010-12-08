//~~ void CodeEnterFunction() [StateChartCoderC] ~~

spec << "//! @brief This function calls the current enter Function until a stable state is reached." << std::endl;
spec << "//! @param theEvent The event passed to the actions and guards." << std::endl;

spec << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "_EnterState("
	<< myAdeStatechart->GetName().c_str()
	<< "* me, const "
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent);\n"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "_EnterState("
	<< myAdeStatechart->GetName().c_str()
	<< "* me, const "
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent)\n{"
	<< std::endl;
impl << "\twhile (me->nextState)" << std::endl;
impl << "\t\t(me->nextState)(me, theEvent);" << std::endl;
impl << "}\n" << std::endl;
