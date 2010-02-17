spec << "\t//! @brief The function pointer to the enter function of the next state." << std::endl;
spec << "\tvoid ("
	<< myAdeStatechart->GetName().c_str()
	<< "::*nextState)("
	<< EventTypeConst
	<< EventType
	<< "&);\n"
	<< std::endl;
