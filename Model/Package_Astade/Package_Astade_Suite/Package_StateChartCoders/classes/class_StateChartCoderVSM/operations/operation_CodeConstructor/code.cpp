//~~ void CodeConstructor() [StateChartCoderVSM] ~~

spec << "\t\t//! @brief Constructor." << std::endl;
spec << "\t\t"
	<< myAdeStatechart->GetName().c_str()
	<< "(long liMachineID, const char acMachineName[]);\n"
	<< std::endl;

impl << myAdeStatechart->GetName().c_str()
	<< "::"
	<< myAdeStatechart->GetName().c_str()
	<< "(long liMachineID, const char acMachineName[]) :"
	<< std::endl;
impl << "\tCVirtualStateMachine(liMachineID,acMachineName)," << std::endl;
impl << "\tm_RunningTimer(0)" << std::endl;
impl << "{" << std::endl;
impl << "}\n" << std::endl;
