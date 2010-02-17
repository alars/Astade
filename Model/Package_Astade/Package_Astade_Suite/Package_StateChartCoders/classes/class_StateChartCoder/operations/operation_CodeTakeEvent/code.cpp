spec << "\t//! @brief Call this function to pass an event to the state machine." << std::endl;
spec << "\t//! All events for this state machine must inherit from the event base class: \""
	<< myAdeStatechart->GetEventType().c_str()
	<< "\""
	<< std::endl;
spec << "\t//! Calling this function is allowed only after calling the \"Initialize\" function." << std::endl;
spec << "\t//! @param theEvent The event to be processed." << std::endl;
spec << "\t//! @param itsID The ID of the event (used for the internal switch case)." << std::endl;
spec << "\t//! @return Boolean whether the event was \"taken\" (there was a reaction on that event)." << std::endl;

spec << "\tbool TakeEvent(const "
	<< myAdeStatechart->GetEventType().c_str()
	<< "& theEvent, eventIDs itsID);\n"
	<< std::endl;

impl << "bool "
	<< myAdeStatechart->GetName().c_str()
	<< "::TakeEvent(const "
	<< myAdeStatechart->GetEventType().c_str()
	<< "& theEvent, eventIDs itsID)"
	<< std::endl;
impl << "{" << std::endl;
impl << "\tbool ret = (this->*theState)(theEvent, itsID);" << std::endl;
impl << "\t// Call the state enter function" << std::endl;
impl << "\tEnterState(theEvent);" << std::endl;
impl << "\treturn ret;" << std::endl;
impl << "}\n" << std::endl;
