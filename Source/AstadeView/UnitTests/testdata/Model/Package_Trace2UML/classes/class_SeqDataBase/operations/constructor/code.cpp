classWidth.reserve(MAXCLASSCOUNT);
classCenter.reserve(MAXCLASSCOUNT);

eventQueue.clear();
eventQueue.reserve(MAXCLASSCOUNT);

int i;

for (i=0; i < MAXCLASSCOUNT; i++)
{
	std::list<int> e;
	eventQueue.push_back(e);
}

for (i=0; i < MAXCLASSCOUNT; ++i)
	classWidth[i] = 90;