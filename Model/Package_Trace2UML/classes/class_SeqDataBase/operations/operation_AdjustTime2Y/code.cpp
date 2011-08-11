//~~ void AdjustTime2Y(int time, int value) [SeqDataBase] ~~
if ((time>0) && (static_cast<unsigned int>(time) < itsEvents.size()))
	itsEvents[time].time += value;
