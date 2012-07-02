//~~ void CodeConstructor() [StateChartCoderACFp] ~~

spec << "\t//! @brief Constructor." << std::endl;
spec << "\t"
	<< myAdeStatechart->GetName().utf8_str()
	<< "(struct ACF* anACF);\n"
	<< std::endl;

spec << "\t//! @brief Destructor." << std::endl;
spec << "\tvirtual ~"
	<< myAdeStatechart->GetName().utf8_str()
	<< "();\n"
	<< std::endl;

impl << myAdeStatechart->GetName().utf8_str()
	<< "::"
	<< myAdeStatechart->GetName().utf8_str()
	<< "(struct ACF* anACF)"
	<< std::endl;

impl << "{" << std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_Trace ACF_LOCALTRACEHELPER;\n"
	<< "\tACF_Trace_notify_constructor(&ACF_LOCALTRACEHELPER,&MessageReceiver_base, 5, \""
	<< myAdeStatechart->GetName().utf8_str()
	<< "\");"
	<< std::endl;
impl << "\t#endif" << std::endl;

impl << "\t// Call the message framework constructor" << std::endl;
impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_MessageReceiver_Constructor(&MessageReceiver_base, \""
	<< myAdeStatechart->GetName().utf8_str()
	<< "\", &"
	<< myAdeStatechart->GetName().utf8_str()
	<< "::TakeEvent, this, anACF);"
	<< std::endl;
impl << "\t#else" << std::endl;
impl << "\tACF_MessageReceiver_Constructor(&MessageReceiver_base, 0, &"
	<< myAdeStatechart->GetName().utf8_str()
	<< "::TakeEvent, this, anACF);"
	<< std::endl;
impl << "\t#endif" << std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_Trace_notifyReturn(&ACF_LOCALTRACEHELPER);" << std::endl;
impl << "\t#endif" << std::endl;

impl << "}\n" << std::endl;

impl << myAdeStatechart->GetName().utf8_str()
	<< "::~"
	<< myAdeStatechart->GetName().utf8_str()
	<< "()"
	<< std::endl;
impl << "{" << std::endl;
impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_Trace ACF_LOCALTRACEHELPER;\n"
	<< "\tACF_Trace_notify_destructor(&ACF_LOCALTRACEHELPER,&MessageReceiver_base, 5, \""
	<< myAdeStatechart->GetName().utf8_str()
	<< "\");"
	<< std::endl;
impl << "\t#endif" << std::endl;

impl << "\tACF_MessageReceiver_Destructor(&MessageReceiver_base);" << std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_Trace_notifyReturn(&ACF_LOCALTRACEHELPER);" << std::endl;
impl << "\t#endif" << std::endl;

impl << "}\n" << std::endl;
