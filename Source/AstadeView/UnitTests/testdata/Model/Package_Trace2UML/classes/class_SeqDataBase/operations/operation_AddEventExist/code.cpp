if (object1 == wxNOT_FOUND)
	return;

itsEvents.push_back(SeqEvent(wxNOT_FOUND,object1,ID_EXIST,wxEmptyString,wxEmptyString));

int possibleHight = GetClassBoxHight();
int test = itsEvents.size()-2;

while (	(possibleHight > 0) &&
		(test > 0) &&
		(itsEvents[test].eventID != ID_NOP) &&
		(itsEvents[test].eventID != ID_COMMENT)
	  )
{
	possibleHight -= (itsEvents[test].time - itsEvents[test-1].time);
	--test;
}

if (possibleHight < 0)
	possibleHight = 0;

itsEvents.back().time = itsEvents[itsEvents.size()-2].time + possibleHight;