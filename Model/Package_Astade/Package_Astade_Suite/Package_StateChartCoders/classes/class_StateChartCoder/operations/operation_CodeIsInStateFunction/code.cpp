//~~ void CodeIsInStateFunction(AdeState& theState) [StateChartCoder] ~~

spec << "\t//! @brief This checks if the machine is in state \""
	<< theState.GetName().utf8_str()
	<< "\"."
	<< std::endl;
spec << "\t//! @return is in state." << std::endl;
spec << "\tinline bool IsIn"
	<< theState.GetName().utf8_str()
	<< "() { return theState == &"
	<< myAdeStatechart->GetName().utf8_str()
	<< "::"
	<< theState.GetName().utf8_str()
	<< "; }\n"
	<< std::endl;
