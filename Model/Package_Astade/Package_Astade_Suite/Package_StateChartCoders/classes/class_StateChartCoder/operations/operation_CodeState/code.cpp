//~~ void CodeState() [StateChartCoder] ~~

spec << "\t//! @brief The pointer holding the current state." << std::endl;
spec << "\tbool ("
	<< myAdeStatechart->GetName().utf8_str()
	<< "::*theState)("
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "&, eventIDs);\n"
	<< std::endl;
