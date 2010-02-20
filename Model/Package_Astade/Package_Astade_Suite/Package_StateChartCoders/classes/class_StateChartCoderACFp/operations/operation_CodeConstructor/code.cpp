spec << "\t//! @brief Constructor." << std::endl;
spec << "\t"
	<< myAdeStatechart->GetName().c_str()
	<< "();\n"
	<< std::endl;

spec << "\t//! @brief Destructor." << std::endl;
spec << "\tvirtual ~"
	<< myAdeStatechart->GetName().c_str()
	<< "();\n"
	<< std::endl;

impl << myAdeStatechart->GetName().c_str()
	<< "::"
	<< myAdeStatechart->GetName().c_str()
	<< "()"
	<< std::endl;
    
impl << "{" << std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tNOTIFY_CONSTRUCTOR(5, \""
	<< myAdeStatechart->GetName()
	<< "\", \" \")"
	<< std::endl;
impl << "\t#endif" << std::endl;

impl << "\t// Call the message framework constructor" << std::endl;
impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tACF_MessageReceiver_Constructor(&MessageReceiver_base, \""
	<< myAdeStatechart->GetName()
	<< "\", &"
	<< myAdeStatechart->GetName()
	<< "::TakeEvent, this);"
	<< std::endl;
impl << "\t#else" << std::endl;
impl << "\tACF_MessageReceiver_Constructor(&MessageReceiver_base, 0, &"
	<< myAdeStatechart->GetName()
	<< "::TakeEvent, this);"
	<< std::endl;
impl << "\t#endif" << std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tvoidRETURN;" << std::endl;
impl << "\t#endif" << std::endl;

impl << "}\n" << std::endl;

impl << myAdeStatechart->GetName().c_str()
	<< "::~"
	<< myAdeStatechart->GetName().c_str()
	<< "()"
	<< std::endl;
impl << "{" << std::endl;
impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tNOTIFY_DESTRUCTOR(5, \""
	<< myAdeStatechart->GetName()
	<< "\")"
	<< std::endl;
impl << "\t#endif" << std::endl;

impl << "\tACF_MessageReceiver_Destructor(&MessageReceiver_base);" << std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tvoidRETURN;" << std::endl;
impl << "\t#endif" << std::endl;

impl << "}\n" << std::endl;
