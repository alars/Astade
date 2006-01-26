itsEvents.clear();
classes.Clear();
eventQueue.clear();
eventQueue.reserve(MAXCLASSCOUNT);
for (int i=0; i < MAXCLASSCOUNT; i++)
{
	std::list<int> e;
	eventQueue.push_back(e);
}

longestTimeStamp = 0;