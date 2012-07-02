//~~ void CodeInitialize() [StateChartCoder] ~~

spec << "\t//! @brief Call this function once to initialize the state machine." << std::endl;
spec << "\t//! Calling this function a second time will have no effect!" << std::endl;
spec << "\t//! This will call all initial actions and enter state \""
	<< myAdeStatechart->GetInitialState().utf8_str()
	<< "\"."
	<< std::endl;
spec << "\t//! The actions are called with the event passed to this function." << std::endl;
spec << "\t//! @param theEvent The event passed to the initial actions." << std::endl;
spec << "\tvoid Initialize("
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "& theEvent);\n"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().utf8_str()
	<< "::Initialize("
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "& theEvent)"
	<< std::endl;
impl << "{" << std::endl;

impl << "\t// Calling the initial actions" << std::endl;

std::list<wxString> aList(myAdeStatechart->GetInitialActions());
for (std::list<wxString>::iterator iter = aList.begin(); iter != aList.end(); ++iter)
	impl << "\t"
		<< iter->utf8_str()
		<< "(theEvent);"
		<< std::endl;

impl << "\t// Set the initial State function" << std::endl;
impl << "\tnextState = &"
	<< myAdeStatechart->GetName().utf8_str()
	<< "::Enter_"
	<< myAdeStatechart->GetInitialState().utf8_str()
	<< ";"
	<< std::endl;

impl << "\t// Call the state enter function" << std::endl;
impl << "\tEnterState(theEvent);" << std::endl;

impl << "}\n" << std::endl;
