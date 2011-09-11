if (object1 == wxNOT_FOUND)
	return;

itsEvents.push_back(SeqEvent(wxNOT_FOUND,object1,ID_EXIST,wxEmptyString,wxEmptyString));

int possibleHeight = GetClassBoxHeight();
int test = itsEvents.size() - 2;

while (	(possibleHeight > 0) &&
		(test > 0) &&
		(itsEvents[test].eventID != ID_NOP) &&
		(itsEvents[test].eventID != ID_COMMENT)
	  )
{
	possibleHeight -= (itsEvents[test].time - itsEvents[test-1].time);
	--test;
}

if (possibleHeight < 0)
	possibleHeight = 0;

itsEvents.back().time = itsEvents[itsEvents.size()-2].time + possibleHeight;
