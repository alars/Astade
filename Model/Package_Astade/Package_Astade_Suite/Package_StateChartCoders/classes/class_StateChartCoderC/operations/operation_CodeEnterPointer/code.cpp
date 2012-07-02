//~~ void CodeEnterPointer() [StateChartCoderC] ~~

spec << "\t//! @brief The pointer to the enter function of the next state." << std::endl;
spec << "\tvoid (*nextState)(struct "
	<< myAdeStatechart->GetName().utf8_str()
	<< "* me, const "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "*);\n"
	<< std::endl;
