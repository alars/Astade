if (object2 == wxNOT_FOUND)
	return;

AddEventReceive(object1,object2,label,timeStamp);
itsEvents.back().time = itsEvents[itsEvents.size()-2].time + 17;