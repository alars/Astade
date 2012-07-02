//~~ void CodeConstructor() [StateChartCoderWx] ~~

spec << "\t//! @brief Constructor." << std::endl;
spec << "\t"
	<< myAdeStatechart->GetName().utf8_str()
	<< "();\n"
	<< std::endl;

spec << "\t//! @brief Destructor." << std::endl;
spec << "\tvirtual ~"
	<< myAdeStatechart->GetName().utf8_str()
	<< "();\n"
	<< std::endl;

impl << myAdeStatechart->GetName().utf8_str()
	<< "::"
	<< myAdeStatechart->GetName().utf8_str()
	<< "() : wxTimer(this, TIMER_ID)"
	<< std::endl;
impl << "{" << std::endl;

impl << "\tNOTIFY_CONSTRUCTOR(5,\""
	<< myAdeStatechart->GetName().utf8_str()
	<< "\",\"\")"
	<< std::endl;

impl << "\ttheState = &"
	<< myAdeStatechart->GetName().utf8_str()
	<< "::NoState;"
	<< std::endl;
impl << "\tnextState = 0;" << std::endl;
impl << "}\n" << std::endl;

impl << myAdeStatechart->GetName().utf8_str()
	<< "::~"
	<< myAdeStatechart->GetName().utf8_str()
	<< "()"
	<< std::endl;
impl << "{" << std::endl;

impl << "\tNOTIFY_DESTRUCTOR(5,\""
	<< myAdeStatechart->GetName().utf8_str()
	<< "\")"
	<< std::endl;

impl << "}\n" << std::endl;
