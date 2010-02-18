spec << "\t//! @brief Call this function to pass an event to the state machine." << std::endl;
spec << "\t//! All events for this state machine must be derived from the event base class: \""
	<< myAdeStatechart->GetEventType().c_str()
	<< "\""
	<< std::endl;
spec << "\t//! Calling this function is allowed only after calling the \"Initialize\" function." << std::endl;
spec << "\t//! @param theEvent The event to be processed." << std::endl;
spec << "\t//! @return Boolean whether the event was \"taken\" (there was a reaction on that event)." << std::endl;

spec << "\tbool TakeEvent("
	<< myAdeStatechart->GetEventType().c_str()
	<< "& theEvent);\n"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "_TakeEvent("
	<< myAdeStatechart->GetName().c_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent)\n"
	<< std::endl;
impl << "{" << std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_Trace ACF_LOCALTRACEHELPER;" << std::endl;
impl << "\tACF_Trace_notify_self_call(&ACF_LOCALTRACEHELPER, me, 5, \""
	<< myAdeStatechart->GetName().c_str()
	<< "\", \"TakeEvent\");"
	<< std::endl;
impl << "\t#endif" << std::endl;

impl << "\t(me->theState)(me, theEvent);" << std::endl;

impl << "\t// Call the state enter function" << std::endl;
impl << "\t"
	<< myAdeStatechart->GetName().c_str()
	<< "_EnterState(me, theEvent);"
	<< std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tvoidRETURN;" << std::endl;
impl << "\t#endif" << std::endl;

impl << "}\n" << std::endl;
