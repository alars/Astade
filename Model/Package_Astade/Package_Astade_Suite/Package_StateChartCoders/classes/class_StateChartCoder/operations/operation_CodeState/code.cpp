spec << "\t//! @brief The pointer holding the current state." << std::endl;
spec << "\tbool ("
	<< myAdeStatechart->GetName().c_str()
	<< "::*theState)(const "
	<< myAdeStatechart->GetEventType().c_str()
	<< "&, eventIDs);\n"
	<< std::endl;
