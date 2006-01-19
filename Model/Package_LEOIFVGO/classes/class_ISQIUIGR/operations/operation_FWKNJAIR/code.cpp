if ((eventNumber<0) || (eventNumber>itsEvents.size()))
	return wxEmptyString;

return itsEvents[eventNumber].aTimeStamp;