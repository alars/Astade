//~~ void CodeTakeEvent() [StateChartCoderQt] ~~
spec << "\t//! Function to call the state function" << std::endl;
spec << "\t//! @param theEvent The event to be processed." << std::endl;
spec << "\tvirtual void TakeEvent(const QString& port, const "
	<< myAdeStatechart->GetEventType().utf8_str()
	<< "& theEvent) { (this->*theState)(port, theEvent); EnterState(port,theEvent);}\n"
	<< std::endl;