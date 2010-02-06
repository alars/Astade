if ((eventNumber < 0) ||
	(static_cast<unsigned>(eventNumber) >= itsEvents.size()))
	return 0;
return itsEvents[eventNumber].destinationObject;