//~~ void CodeIsInStateFunction(AdeState& theState) [StateChartCoderACFp] ~~
spec << "\t//! @brief This checks if the machine is in state \""
	<< theState.GetName().c_str()
	<< "\"."
	<< std::endl;
spec << "\t//! @return is in state." << std::endl;
spec << "\tinline bool IsIn"
	<< theState.GetName().c_str()
	<< "() { return theState == &"
	<< myAdeStatechart->GetName().c_str()
	<< "::"
	<< theState.GetName().c_str()
	<< "; }\n"
	<< std::endl;
