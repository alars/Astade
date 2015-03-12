//~~ void CodeInitialize() [StateChartCoderQt] ~~

spec << "\t//! @brief Call this function once to initialize the state machine." << std::endl;
spec << "\t//! Calling this function a second time will have no effect!" << std::endl;
spec << "\t//! This will call all initial actions and enter state \""
	 << myAdeStatechart->GetInitialState().utf8_str()
	 << "\"."
	 << std::endl;
spec << "\t//! The actions are called with the event passed to this function." << std::endl;
spec << "\tvoid Initialize();\n" << std::endl;

impl << "void "
	 << myAdeStatechart->GetName().utf8_str()
	 << "::Initialize()" << std::endl;
impl << "{" << std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_Trace ACF_LOCALTRACEHELPER;\n"
	<< "\tACF_Trace_notify_function_call(&ACF_LOCALTRACEHELPER,&MessageReceiver_base, 5, \""
	<< myAdeStatechart->GetName().utf8_str()
	<< "\", \"Initialize\");"
	<< std::endl;
impl << "\t#endif" << std::endl;

std::list<wxString> aList = myAdeStatechart->GetInitialActions();

impl << "\t// Calling the initial actions" << std::endl;

for (std::list<wxString>::iterator iter = aList.begin(); iter != aList.end(); ++iter)
	impl << "\t"
		<< iter->utf8_str()
		<< "(0, AQF_Message());"
		<< std::endl;

impl << "\t// Set the initial State function" << std::endl;
impl << "\tnextState = &"
	 << myAdeStatechart->GetName().utf8_str()
	 << "::Enter_"
	 << myAdeStatechart->GetInitialState().utf8_str()
	 << ";"
	 << std::endl;

impl << "\t// Call the state enter function" << std::endl;
impl << "\t"
	 << "EnterState(0, AQF_Message());"
	 << std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_Trace_notifyReturn(&ACF_LOCALTRACEHELPER);" << std::endl;
impl << "\t#endif" << std::endl;
impl << "}\n" << std::endl;
