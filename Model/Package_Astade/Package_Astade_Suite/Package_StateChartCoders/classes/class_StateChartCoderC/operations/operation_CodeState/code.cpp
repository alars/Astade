//~~ void CodeState() [StateChartCoderC] ~~

spec << "\t//! @brief The pointer holding the current state." << std::endl;
spec << "\tbool (*theState)(struct "
	<< myAdeStatechart->GetName().utf8_str()
	<< "* me, const "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "*, "
	<< myAdeStatechart->GetName().utf8_str()
	<< "_eventIDs);\n"
	<< std::endl;
