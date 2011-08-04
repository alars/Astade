//~~ int GetTime2Y(int time) [SeqDataBase] ~~
if ((time>0) && (static_cast<unsigned int>(time) < itsEvents.size()))
	return 	itsEvents[time].time;
else
	return 0;