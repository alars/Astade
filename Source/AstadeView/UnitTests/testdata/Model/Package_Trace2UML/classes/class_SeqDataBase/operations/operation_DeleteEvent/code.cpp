if ((eventNumber < 0) ||
	(static_cast<unsigned>(eventNumber) >= itsEvents.size()))
	return;

for (unsigned i = eventNumber; i < itsEvents.size()-1; ++i)
	itsEvents[i] = itsEvents[i+1];
itsEvents.pop_back();