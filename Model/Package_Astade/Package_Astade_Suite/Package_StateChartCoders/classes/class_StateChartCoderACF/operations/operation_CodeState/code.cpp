//~~ void CodeState() [StateChartCoderACF] ~~
spec << "\t//! @brief The state-chart is an ACF_MessageReceiver so we need this member here first." << std::endl;
spec << "\tACF_MessageReceiver MessageReceiver_base;\n" << std::endl;

spec << "\t//! @brief The pointer holding the current state." << std::endl;
spec << "\tvoid (*theState)(struct "
	<< myAdeStatechart->GetName().c_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent);\n"
	<< std::endl;
