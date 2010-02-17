spec << "\t//! @brief Call this function once to initialize the state machine." << std::endl;
spec << "\t//! Calling this function a second time will have no effect!" << std::endl;
spec << "\t//! This will call all initial actions and enter state \""
	<< myAdeStatechart->GetInitialState().c_str()
	<< "\"."
	<< std::endl;
spec << "\t//! The actions are called with the event passed to this function." << std::endl;
spec << "\t//! @param theEvent The event passed to the initial actions." << std::endl;
spec << "\tvoid Initialize("
	<< myAdeStatechart->GetEventType().c_str()
	<< "& theEvent);\n"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "::Initialize("
	<< myAdeStatechart->GetEventType().c_str()
	<< "& theEvent)"
	<< std::endl;
impl << "{" << std::endl;

impl << "\t// Calling the initial actions" << std::endl;

std::set<wxString> aSet(myAdeStatechart->GetInitialActions());
for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
	impl << "\t"
		<< (*iter).c_str()
		<< "(theEvent);"
		<< std::endl;

impl << "\t// Set the initial State function" << std::endl;
impl << "\tnextState = &"
	<< myAdeStatechart->GetName().c_str()
	<< "::Enter_"
	<< myAdeStatechart->GetInitialState().c_str()
	<< ";"
	<< std::endl;

impl << "\t// Call the state enter function" << std::endl;
impl << "\tEnterState(theEvent);" << std::endl;

impl << "}\n" << std::endl;
