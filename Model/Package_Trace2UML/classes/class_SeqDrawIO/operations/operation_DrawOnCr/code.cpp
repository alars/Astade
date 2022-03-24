//~~ void DrawOnCr(std::ofstream& cr) [SeqDrawIO] ~~
int eventsCount = dataBase->GetEventsCount();

eventQueue.clear();
eventQueue.reserve(dataBase->GetClassCount());

while ((int)thickness.size() < dataBase->GetClassCount())
    thickness.push_back(0);

while ((int)classEvent.size() < dataBase->GetClassCount())
    classEvent.push_back(0);

int i;
for (i = 0; i < dataBase->GetClassCount(); i++)
{
	thickness[i] = -1;
	std::list<int> e;
	eventQueue.push_back(e);
}

// Now all the events
for (i = 0; i < eventsCount; i++)
	DrawEvent(cr, i);

for (i = 0; i < dataBase->GetClassCount(); i++)
	while (!eventQueue[i].empty())
	{
		DrawLostEvent(cr, eventQueue[i].front());
		eventQueue[i].pop_front();
	}
