//~~ void CodeNoState() [StateChartCoderACF] ~~
spec << "//! @brief This is the default state before the state machine is initialized." << std::endl;
spec << "//! It does nothing. This makes sure that there is no crash if \"TakeEvent\" is called accidentally before \"Initialize\"." << std::endl;

spec << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "_NoState("
	<< myAdeStatechart->GetName().c_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent);\n"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "_NoState("
	<< myAdeStatechart->GetName().c_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent)"
	<< std::endl;
impl << "{" << std::endl;
impl << "\treturn;" << std::endl;
impl << "}\n" << std::endl;
