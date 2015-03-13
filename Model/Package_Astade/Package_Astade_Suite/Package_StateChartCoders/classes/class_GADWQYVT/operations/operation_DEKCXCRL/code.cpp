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

impl << "\ttheState = &" << myAdeStatechart->GetName().utf8_str() << "::NoState;" << std::endl;

impl << "}\n" << std::endl;

impl << myAdeStatechart->GetName().utf8_str()
	<< "::~"
	<< myAdeStatechart->GetName().utf8_str()
	<< "()"
	<< std::endl;
impl << "{" << std::endl;
impl << "}\n" << std::endl;
