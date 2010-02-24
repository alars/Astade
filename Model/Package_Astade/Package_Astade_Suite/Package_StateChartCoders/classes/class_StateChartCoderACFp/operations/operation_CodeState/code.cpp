spec << "\t//! @brief The pointer holding the current state." << std::endl;
spec << "\tvoid ("
	<< myAdeStatechart->GetName().c_str()
	<< "::*theState)("
	<< myAdeStatechart->GetEventType().c_str()
	<< "*);\n"
	<< std::endl;
