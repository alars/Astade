spec << "//! @brief Call this function once to initialize the state machine." << std::endl;
spec << "//! Calling this function a second time will have no effect!" << std::endl;
spec << "//! This will call all initial actions and enter state \""
	<< myAdeStatechart->GetInitialState().c_str()
	<< "\"."
	<< std::endl;
spec << "//! The actions are called with the event passed to this function." << std::endl;
spec << "//! @param me A pointer to the statechart instance." << std::endl;
spec << "//! @param theEvent The event passed to the initial actions." << std::endl;
spec << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "_Initialize("
	<< myAdeStatechart->GetName().c_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent);\n"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().c_str()
	<< "_Initialize("
	<< myAdeStatechart->GetName().c_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent)"
	<< std::endl;
impl << "{" << std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tNOTIFY_FUNCTION_CALL(me, 5, \""
	<< myAdeStatechart->GetName().c_str()
	<< "\", \"Initialize\", \" \", \" \")"
	<< std::endl;
impl << "\t#endif" << std::endl;

std::set<wxString> aSet;
aSet = myAdeStatechart->GetInitialActions();

impl << "\t// Calling the initial actions" << std::endl;

for (std::set<wxString>::iterator iter = aSet.begin(); iter != aSet.end(); ++iter)
	impl << "\t"
		<< myAdeStatechart->GetName().c_str()
		<< "_impl_"
		<< (*iter).c_str()
		<< "(me, theEvent);"
		<< std::endl;

impl << "\t// Set the initial State function" << std::endl;
impl << "\tme->nextState = &"
	<< myAdeStatechart->GetName().c_str()
	<< "_Enter_"
	<< myAdeStatechart->GetInitialState().c_str()
	<< ";"
	<< std::endl;

impl << "\t// Call the state enter function" << std::endl;
impl << "\t"
	<< myAdeStatechart->GetName().c_str()
	<< "_EnterState(me, theEvent);"
	<< std::endl;

impl << "\t#ifdef _TRACE_" << std::endl;
impl << "\tvoidRETURN;" << std::endl;
impl << "\t#endif" << std::endl;
impl << "}\n" << std::endl;
