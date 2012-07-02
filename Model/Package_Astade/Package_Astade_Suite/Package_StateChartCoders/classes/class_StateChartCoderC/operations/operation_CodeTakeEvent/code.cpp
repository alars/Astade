//~~ void CodeTakeEvent() [StateChartCoderC] ~~

spec << "//! @brief Call this function to pass an event to the state machine." << std::endl;
spec << "//! All events for this state machine must inherit from the event base class: \""
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "\""
	<< std::endl;
spec << "//! Calling this function is allowed only after calling the \"Initialize\" function." << std::endl;
spec << "//! @param me A pointer to the statechart instance." << std::endl;
spec << "//! @param theEvent The event to be processed." << std::endl;
spec << "//! @param itsID The ID of the event (used for the internal switch case)." << std::endl;
spec << "//! @return Boolean whether the event was \"taken\" (there was a reaction on that event)." << std::endl;

spec << "bool "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_TakeEvent("
	<< myAdeStatechart->GetName().utf8_str()
	<< "* me, const "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "* theEvent, "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_eventIDs itsID);\n"
	<< std::endl;

impl << "bool "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_TakeEvent("
	<< myAdeStatechart->GetName().utf8_str()
	<< "* me, const "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "* theEvent, "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_eventIDs itsID)"
	<< std::endl;
impl << "{" << std::endl;
impl << "\tbool ret = (me->theState)(me, theEvent,itsID);" << std::endl;
impl << "\t// Call the state enter function" << std::endl;
impl << "\t"
	<< myAdeStatechart->GetName().utf8_str()
	<< "_EnterState(me, theEvent);"
	<< std::endl;
impl << "\treturn ret;" << std::endl;
impl << "}\n" << std::endl;
