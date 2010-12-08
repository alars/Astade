//~~ void CodeEnterPointer() [StateChartCoderC] ~~

spec << "\t//! @brief The pointer to the enter function of the next state." << std::endl;
spec << "\tvoid (*nextState)(struct "
	<< myAdeStatechart->GetName().c_str()
	<< "* me, const "
	<< myAdeStatechart->GetEventType().c_str()
	<< "*);\n"
	<< std::endl;
