//~~ void CodeNoState() [StateChartCoderVSM] ~~

spec << "\t//! @brief This is the default state before the state machine is initialized." << std::endl;
spec << "\t//! It does nothing but the initial transition." << std::endl;
spec << "\t//! @param message The event to be processed." << std::endl;

spec << "\tvoid ResetState("
	<< myAdeStatechart->GetEventType().c_str()
	<< "& message);\n"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "::ResetState("
	<< myAdeStatechart->GetEventType().c_str()
	<< "& message)"
	<< std::endl;
impl << "{" << std::endl;

impl << "\tif (message.Primitive() == dIID_VFSM_MSG_Init)" << std::endl;
impl << "\t{" << std::endl;
impl << "\t\t// Calling the initial actions" << std::endl;

std::list<wxString> aList = myAdeStatechart->GetInitialActions();
for (std::list<wxString>::iterator iter = aList.begin(); iter != aList.end(); ++iter)
	impl << "\t\t"
		<< (*iter).c_str()
		<< "(message);"
		<< std::endl;

impl << "\t\t// Set the initial State function" << std::endl;
impl << "\t\tnextState = &"
	<< myAdeStatechart->GetName().c_str()
	<< "::Enter_"
	<< myAdeStatechart->GetInitialState().c_str()
	<< ";"
	<< std::endl;

impl << "\t\t// Call the state enter function" << std::endl;
impl << "\t\tEnterState(message);" << std::endl;

impl << "\t}" << std::endl;
impl << "\telse" << std::endl;
impl << "\t\tmessage.NotHandeled();" << std::endl;

impl << "}\n" << std::endl;
