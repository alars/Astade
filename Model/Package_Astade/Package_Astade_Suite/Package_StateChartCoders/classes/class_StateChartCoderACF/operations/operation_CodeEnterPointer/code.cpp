spec << "\t//! @brief The function pointer to the enter function of the next state." << std::endl;
spec << "\tvoid (*nextState)(struct "
	<< myAdeStatechart->GetName().c_str()
	<< "* me, "
	<< myAdeStatechart->GetEventType().c_str()
	<< "* theEvent);\n"
	<< std::endl;
