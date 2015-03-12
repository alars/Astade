//~~ void CodeConstructor() [StateChartCoderQt] ~~

spec << "\t//! @brief Constructor." << std::endl;
spec << "\t" << myAdeStatechart->GetName().utf8_str() << "();\n" << std::endl;

spec << "\t//! @brief Destructor." << std::endl;
spec << "\tvirtual ~"
	<< myAdeStatechart->GetName().utf8_str()
	<< "();\n"
	<< std::endl;

impl << myAdeStatechart->GetName().utf8_str()
	<< "::"
	<< myAdeStatechart->GetName().utf8_str() << "()" << std::endl;

impl << "{" << std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_Trace ACF_LOCALTRACEHELPER;\n"
	<< "\tACF_Trace_notify_constructor(&ACF_LOCALTRACEHELPER,&MessageReceiver_base, 5, \""
	<< myAdeStatechart->GetName().utf8_str()
	<< "\");"
	<< std::endl;
impl << "\t#endif" << std::endl;

impl << "\ttheState = &" << myAdeStatechart->GetName().utf8_str() << "::NoState;" << std::endl;

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

impl << "}\n" << std::endl;
