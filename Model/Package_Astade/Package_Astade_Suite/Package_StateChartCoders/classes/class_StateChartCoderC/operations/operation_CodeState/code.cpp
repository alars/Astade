//~~ void CodeState() [StateChartCoderC] ~~

spec << "\t//! @brief The pointer holding the current state." << std::endl;
spec << "\tbool (*theState)(struct "
	<< myAdeStatechart->GetName().c_str()
	<< "* me, const "
	<< myAdeStatechart->GetEventType().c_str()
	<< "*, "
	<< myAdeStatechart->GetName().c_str()
	<< "_eventIDs);\n"
	<< std::endl;
