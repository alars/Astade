//~~ void CodeConstructor() [StateChartCoderACF] ~~

spec << "//! @brief Constructor." << std::endl;
spec << "extern void "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_Constructor("
	<< myAdeStatechart->GetName().utf8_str()
	<< "* me, ACF* anACF);\n"
	<< std::endl;

spec << "//! @brief Destructor." << std::endl;
spec << "extern void "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_Destructor("
	<< myAdeStatechart->GetName().utf8_str()
	<< "* me);\n"
	<< std::endl;

impl << "//! @brief Constructor." << std::endl;
impl << "void "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_Constructor("
	<< myAdeStatechart->GetName().utf8_str()
	<< "* me, ACF* anACF)"
	<< std::endl;
impl << "{" << std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_Trace ACF_LOCALTRACEHELPER;\n"
	<< "\tACF_Trace_notify_constructor(&ACF_LOCALTRACEHELPER,&me->MessageReceiver_base, 5, \""
	<< myAdeStatechart->GetName().utf8_str()
	<< "\");"
	<< std::endl;
impl << "\t#endif" << std::endl;

impl << "\tme->theState = &"
	<< myAdeStatechart->GetName().utf8_str()
	<< "_NoState;"
	<< std::endl;

impl << "\t// Call the message framework constructor" << std::endl;
impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_MessageReceiver_Constructor(&me->MessageReceiver_base, \""
	<< myAdeStatechart->GetName().utf8_str()
	<< "\", (void(*)(void*, ACF_Message*))&"
	<< myAdeStatechart->GetName().utf8_str()
	<< "_TakeEvent, me, anACF);"
	<< std::endl;
impl << "\t#else" << std::endl;
impl << "\tACF_MessageReceiver_Constructor(&me->MessageReceiver_base, 0, (void(*)(void*, ACF_Message*))&"
	<< myAdeStatechart->GetName().utf8_str()
	<< "_TakeEvent, me, anACF);"
	<< std::endl;
impl << "\t#endif" << std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_Trace_notifyReturn(&ACF_LOCALTRACEHELPER);" << std::endl;
impl << "\t#endif" << std::endl;

impl << "}\n" << std::endl;

impl << "//! \\brief Destructor." << std::endl;
impl << "void "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_Destructor("
	<< myAdeStatechart->GetName().utf8_str()
	<< "* me)"
	<< std::endl;
impl << "{" << std::endl;
impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_Trace ACF_LOCALTRACEHELPER;\n"
	<< "\tACF_Trace_notify_destructor(&ACF_LOCALTRACEHELPER,&me->MessageReceiver_base, 5, \""
	<< myAdeStatechart->GetName().utf8_str()
	<< "\");"
	<< std::endl;
impl << "\t#endif" << std::endl;

impl << "\tACF_cancelTimeout(&me->MessageReceiver_base);" << std::endl;
impl << "\tme->theState = &"
	<< myAdeStatechart->GetName().utf8_str()
	<< "_NoState;"
	<< std::endl;

impl << "\tACF_MessageReceiver_Destructor(&me->MessageReceiver_base);" << std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_Trace_notifyReturn(&ACF_LOCALTRACEHELPER);" << std::endl;
impl << "\t#endif" << std::endl;

impl << "}\n" << std::endl;
