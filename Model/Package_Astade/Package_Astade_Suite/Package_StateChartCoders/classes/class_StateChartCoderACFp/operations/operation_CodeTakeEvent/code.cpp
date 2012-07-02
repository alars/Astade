//~~ void CodeTakeEvent() [StateChartCoderACFp] ~~

spec << "\t//! @brief Call this function to pass an event to the state machine." << std::endl;
spec << "\t//! All events for this state machine must be derived from the event base class: \""
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "\""
	<< std::endl;
spec << "\t//! Calling this function is allowed only after calling the \"Initialize\" function." << std::endl;
spec << "\t//! @param me Pointer to the ACF_MessageReceiver." << std::endl;
spec << "\t//! @param theEvent The event to be processed." << std::endl;

spec << "\tstatic void TakeEvent(void* me, "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "* theEvent);\n"
	<< std::endl;

spec << "\t//! Helper function to call the state function from the static function" << std::endl;
spec << "\t//! @param theEvent The event to be processed." << std::endl;
spec << "\tinline void TakeTheEvent("
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "* theEvent) { (this->*theState)(theEvent); }\n"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().utf8_str()
	<< "::TakeEvent(void* me, "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "* theEvent)"
	<< std::endl;
impl << "{" << std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_Trace ACF_LOCALTRACEHELPER;" << std::endl;
impl << "\tACF_Trace_notify_self_call(&ACF_LOCALTRACEHELPER, me, 5, \""
	<< myAdeStatechart->GetName().utf8_str()
	<< "\", \"TakeEvent\");"
	<< std::endl;
impl << "\t#endif" << std::endl;

impl << "\t"
	<< myAdeStatechart->GetName().utf8_str()
	<< "* pthis = "
	<< "("
	<< myAdeStatechart->GetName().utf8_str()
	<< "*)((ACF_MessageReceiver*)me)->this_ptr;"
	<< std::endl;
impl << "\tpthis->TakeTheEvent(theEvent);"
	<< std::endl;

impl << "\t// Call the state enter function" << std::endl;
impl << "\tpthis->EnterState(theEvent);" << std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_Trace_notifyReturn(&ACF_LOCALTRACEHELPER);" << std::endl;
impl << "\t#endif" << std::endl;

impl << "}\n" << std::endl;
