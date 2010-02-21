spec << "//! @brief Call this function to pass an event to the state machine." << std::endl;
spec << "//! Calling this function is allowed only after calling the \"Initialize\" function." << std::endl;
spec << "//! @param me A pointer to the statechart instance." << std::endl;
spec << "//! @param theEvent The event to be processed." << std::endl;

spec << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "_TakeEvent("
	<< myAdeStatechart->GetName().c_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent);\n"
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
impl << "\tACF_Trace_notifyReturn(&ACF_LOCALTRACEHELPER);" << std::endl;
impl << "\t#endif" << std::endl;

impl << "}\n" << std::endl;
