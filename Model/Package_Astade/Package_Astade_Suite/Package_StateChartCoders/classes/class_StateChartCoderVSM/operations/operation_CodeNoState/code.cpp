//~~ void CodeNoState() [StateChartCoderVSM] ~~

spec << "\t//! @brief This is the default state before the state machine is initialized." << std::endl;
spec << "\t//! It does nothing but the initial transition." << std::endl;
spec << "\t//! @param message The event to be processed." << std::endl;

spec << "\tvoid ResetState("
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "& message);\n"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().utf8_str()
	<< "::ResetState("
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "& message)"
	<< std::endl;
impl << "{" << std::endl;

impl << "\tif (message.Primitive() == dIID_VFSM_MSG_Init)" << std::endl;
impl << "\t{" << std::endl;
impl << "\t\t// Calling the initial actions" << std::endl;

std::list<wxString> aList = myAdeStatechart->GetInitialActions();
for (std::list<wxString>::iterator iter = aList.begin(); iter != aList.end(); ++iter)
	impl << "\t\t"
		<< iter->utf8_str()
		<< "(message);"
		<< std::endl;

impl << "\t\t// Set the initial State function" << std::endl;
impl << "\t\tnextState = &"
	<< myAdeStatechart->GetName().utf8_str()
	<< "::Enter_"
	<< myAdeStatechart->GetInitialState().utf8_str()
	<< ";"
	<< std::endl;

impl << "\t\t// Call the state enter function" << std::endl;
impl << "\t\tEnterState(message);" << std::endl;

impl << "\t}" << std::endl;
impl << "\telse" << std::endl;
impl << "\t\tmessage.NotHandeled();" << std::endl;

impl << "}\n" << std::endl;
