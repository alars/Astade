spec << "\t//! @brief This function calls the current enter Function until a stable state is reached." << std::endl;
spec << "\t//! @param theEvent The event passed to the actions and guards." << std::endl;
spec << "\tvoid EnterState("
	<< myAdeStatechart->GetEventType().c_str()
	<< "& theEvent);"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "_EnterState("
	<< myAdeStatechart->GetName().c_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent)"
	<< std::endl;
impl << "{" << std::endl;
impl << "\twhile (me->nextState)" << std::endl;
impl << "\t\t(me->nextState)(me, theEvent);" << std::endl;
impl << "}" << std::endl;

