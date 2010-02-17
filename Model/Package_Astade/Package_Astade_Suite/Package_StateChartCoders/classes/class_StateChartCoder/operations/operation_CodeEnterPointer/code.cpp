spec << "\t//! @brief The function pointer to the enter function of the next state." << std::endl;
spec << "\tvoid ("
	<< myAdeStatechart->GetName().c_str()
	<< "::*nextState)(const "
	<< myAdeStatechart->GetEventType().c_str()
	<< "&);\n"
	<< std::endl;
