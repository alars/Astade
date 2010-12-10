//~~ void CodeEnterFunction() [StateChartCoderVSM] ~~

spec <<"\t//! @brief This function calls the current enter Function until a stable state is reached." << std::endl;
spec <<"\t//! @param message The event passed to the actions and guards." << std::endl;
spec << "\tvoid EnterState("
	<< myAdeStatechart->GetEventType().c_str()
	<< "& message);"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "::EnterState("
	<< myAdeStatechart->GetEventType().c_str()
	<< "& message)"
	<< std::endl;
impl << "{" << std::endl;
impl << "\twhile (nextState)" << std::endl;
impl << "\t\t(this->*nextState)(message);" << std::endl;
impl << "}\n" << std::endl;
