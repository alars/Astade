//~~ void CodeInitialize() [StateChartCoderACF] ~~

spec << "//! @brief Call this function once to initialize the state machine." << std::endl;
spec << "//! Calling this function a second time will have no effect!" << std::endl;
spec << "//! This will call all initial actions and enter state \""
	<< myAdeStatechart->GetInitialState().utf8_str()
	<< "\"."
	<< std::endl;
spec << "//! The actions are called with the event passed to this function." << std::endl;
spec << "//! @param me A pointer to the statechart instance." << std::endl;
spec << "//! @param theEvent The event passed to the initial actions." << std::endl;
spec << "void "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_Initialize("
	<< myAdeStatechart->GetName().utf8_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "* theEvent);\n"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_Initialize("
	<< myAdeStatechart->GetName().utf8_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "* theEvent)"
	<< std::endl;
impl << "{" << std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_Trace ACF_LOCALTRACEHELPER;\n"
	<< "\tACF_Trace_notify_function_call(&ACF_LOCALTRACEHELPER,&me->MessageReceiver_base, 5, \""
	<< myAdeStatechart->GetName()
	<< "\", \"Initialize\");"
	<< std::endl;
impl << "\t#endif" << std::endl;

std::list<wxString> aList = myAdeStatechart->GetInitialActions();

impl << "\t// Calling the initial actions" << std::endl;

for (std::list<wxString>::iterator iter = aList.begin(); iter != aList.end(); ++iter)
	impl << "\t"
		<< myAdeStatechart->GetName().utf8_str()
		<< "_impl_"
		<< iter->utf8_str()
		<< "(("
		<< myAdeStatechart->GetName().utf8_str()
		<< "_impl*)me, theEvent);"
		<< std::endl;

impl << "\t// Set the initial State function" << std::endl;
impl << "\tme->nextState = &"
	<< myAdeStatechart->GetName().utf8_str()
	<< "_Enter_"
	<< myAdeStatechart->GetInitialState().utf8_str()
	<< ";"
	<< std::endl;

impl << "\t// Call the state enter function" << std::endl;
impl << "\t"
	<< myAdeStatechart->GetName().utf8_str()
	<< "_EnterState(me, theEvent);"
	<< std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_Trace_notifyReturn(&ACF_LOCALTRACEHELPER);" << std::endl;
impl << "\t#endif" << std::endl;
impl << "}\n" << std::endl;
