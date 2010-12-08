//~~ void CodeIsInStateFunction(AdeState& theState) [StateChartCoderC] ~~

spec << "//! @brief This checks if the machine is in state \""
	<< theState.GetName().c_str()
	<< "\"."
	<< std::endl;
spec << "//! @param me A pointer to the statechart instance." << std::endl;
spec << "//! @return is in state." << std::endl;
spec << "inline bool "
	<< myAdeStatechart->GetName().c_str()
	<< "_IsIn"
	<< theState.GetName().c_str()
	<< "("
	<< myAdeStatechart->GetName().c_str()
	<< "* me) { return me->theState == &"
	<< myAdeStatechart->GetName().c_str()
	<< "_"
	<< theState.GetName().c_str()
	<< "; };\n"
	<< std::endl;
