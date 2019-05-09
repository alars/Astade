//~~ void CodeEnterFunction() [StateChartCoderQt] ~~

spec << "\t//! @brief This function calls the current enter Function until a stable state is reached." << std::endl;
spec << "\t//! @param port The machine which send this message." << std::endl;
spec << "\t//! @param theEvent The event passed to the actions and guards." << std::endl;
spec << "\tvoid EnterState(const AQF_MessageReceiver* port, const "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "& theEvent);"
	<< std::endl;

impl << "void "
	<< myAdeStatechart->GetName().utf8_str()
	<< "::EnterState(const AQF_MessageReceiver* port, const "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "& theEvent)"
	<< std::endl;
impl << "{" << std::endl;

impl << "\tbool continueExecution;" << std::endl;
impl << "\tif (nextState) do" << std::endl;
impl << "\t{" << std::endl;
impl << "\t\tcontinueExecution = (this->*nextState)(port, theEvent);" << std::endl;
impl << "\t} while (continueExecution && nextState);" << std::endl;
impl << "}" << std::endl;
