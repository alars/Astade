spec << "\t//! @brief Call this function to pass an event to the state machine." << std::endl;
spec << "\t//! All events for this state machine must be derived from the event base class: \""
	<< EventType
	<< "\""
	<< std::endl;
spec << "\t//! Calling this function is allowed only after calling the \"Initialize\" function." << std::endl;
spec << "\t//! @param theEvent The event to be processed." << std::endl;
spec << "\t//! @return Boolean whether the event was \"taken\" (there was a reaction on that event)." << std::endl;

spec << "\tbool TakeEvent("
	<< EventTypeConst
	<< EventType
	<< "& theEvent);\n"
	<< std::endl;

impl << "bool "
	<< myAdeStatechart->GetName().c_str()
	<< "::TakeEvent("
	<< EventTypeConst
	<< EventType
	<< "& theEvent)"
	<< std::endl;
impl << "{" << std::endl;
impl << "\tbool ret = (this->*theState)(theEvent);" << std::endl;
impl << "\t// Call the state enter function" << std::endl;
impl << "\tEnterState(theEvent);" << std::endl;
impl << "\treturn ret;" << std::endl;
impl << "}\n" << std::endl;
