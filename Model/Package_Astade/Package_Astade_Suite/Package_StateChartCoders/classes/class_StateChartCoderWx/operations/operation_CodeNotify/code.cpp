spec << "\t//! @brief This function implements the Timeout. When the Timeout expires this function calls TakeEvent with a Timer event." << std::endl;
spec << "\tvirtual void Notify();\n" << std::endl;

impl << "void "
	<< myAdeStatechart->GetName()
	<< "::Notify()"
	<< std::endl;
impl << "{" << std::endl; 

impl << "#if wxCHECK_VERSION(2,9,0)" << std::endl;
impl << "\twxTimerEvent anEvent(*this);" << std::endl;
impl << "#else" << std::endl;
impl << "\twxTimerEvent anEvent(TIMER_ID);" << std::endl;
impl << "#endif" << std::endl;
impl << "\tTakeEvent(anEvent);" << std::endl;

impl << "}\n" << std::endl;
