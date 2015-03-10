//~~ void CodeEnterPointer() [StateChartCoderACF] ~~

spec << "\t//! @brief The function pointer to the enter function of the next state." << std::endl;
spec << "\tvoid (*nextState)(struct "
	<< myAdeStatechart->GetName().utf8_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "* theEvent);\n"
	<< std::endl;
