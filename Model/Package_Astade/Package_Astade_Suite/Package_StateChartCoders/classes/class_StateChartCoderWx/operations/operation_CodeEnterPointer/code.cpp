//~~ void CodeEnterPointer() [StateChartCoderWx] ~~

spec << "\t//! @brief The function pointer to the enter function of the next state." << std::endl;
spec << "\tvoid ("
	<< myAdeStatechart->GetName().utf8_str()
	<< "::*nextState)("
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "&);\n"
	<< std::endl;
