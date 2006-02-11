if (itsEvents.empty())
	return GetLowerBorder();
else
	return itsEvents.back().time + GetLowerBorder();