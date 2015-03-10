//~~ void CodeNoState() [StateChartCoderACF] ~~

spec << "//! @brief This is the default state before the state machine is initialized." << std::endl;
spec << "//! It does nothing. This makes sure that there is no crash if \"TakeEvent\" is called accidentally before \"Initialize\"." << std::endl;

spec << "void "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_NoState("
	<< myAdeStatechart->GetName().utf8_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "* theEvent);\n"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_NoState("
	<< myAdeStatechart->GetName().utf8_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "* theEvent)"
	<< std::endl;
impl << "{" << std::endl;
impl << "\treturn;" << std::endl;
impl << "}\n" << std::endl;
