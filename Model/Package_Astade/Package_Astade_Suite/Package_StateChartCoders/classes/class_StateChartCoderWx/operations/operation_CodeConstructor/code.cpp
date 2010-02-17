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
	<< "() : wxTimer(this, TIMER_ID)"
	<< std::endl;
impl << "{" << std::endl;
impl << "\ttheState = &"
	<< myAdeStatechart->GetName().c_str()
	<< "::NoState;"
	<< std::endl;
impl << "\tnextState = 0;" << std::endl;
impl << "}\n" << std::endl;

impl << myAdeStatechart->GetName().c_str()
	<< "::~"
	<< myAdeStatechart->GetName().c_str()
	<< "()"
	<< std::endl;
impl << "{" << std::endl;
impl << "}\n" << std::endl;
