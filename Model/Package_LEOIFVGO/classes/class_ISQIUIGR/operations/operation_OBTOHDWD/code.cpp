if (eventNumber < itsEvents.size())
{
	for (int i = eventNumber; i < itsEvents.size()-1; ++i)
		itsEvents[i] = itsEvents[i+1];
	itsEvents.pop_back();
}