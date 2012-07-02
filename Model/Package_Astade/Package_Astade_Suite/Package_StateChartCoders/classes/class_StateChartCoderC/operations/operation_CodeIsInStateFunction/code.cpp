//~~ void CodeIsInStateFunction(AdeState& theState) [StateChartCoderC] ~~

spec << "//! @brief This checks if the machine is in state \""
	<< theState.GetName().utf8_str()
	<< "\"."
	<< std::endl;
spec << "//! @param me A pointer to the statechart instance." << std::endl;
spec << "//! @return is in state." << std::endl;
spec << "inline bool "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_IsIn"
	<< theState.GetName().utf8_str()
	<< "("
	<< myAdeStatechart->GetName().utf8_str()
	<< "* me) { return me->theState == &"
	<< myAdeStatechart->GetName().utf8_str()
	<< "_"
	<< theState.GetName().utf8_str()
	<< "; };\n"
	<< std::endl;
