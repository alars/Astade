//~~ void CodeConstructor() [StateChartCoderVSM] ~~

spec << "\t//! @brief Constructor." << std::endl;
spec << "\t"
	<< myAdeStatechart->GetName().utf8_str()
	<< "(long liMachineID, const char acMachineName[]);\n"
	<< std::endl;

impl << myAdeStatechart->GetName().utf8_str()
	<< "::"
	<< myAdeStatechart->GetName().utf8_str()
	<< "(long liMachineID, const char acMachineName[]) :"
	<< std::endl;
impl << "\tCVirtualStateMachine(liMachineID,acMachineName)," << std::endl;
impl << "\tm_RunningTimer(0)" << std::endl;
impl << "{" << std::endl;
impl << "}\n" << std::endl;
