dc.SetFont(wxFont(8, wxFONTFAMILY_SWISS , wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL ));

int eventsCount = dataBase->GetEventsCount();

int i;

eventQueue.clear();
eventQueue.reserve(dataBase->GetClassCount());

thickness.reserve(dataBase->GetClassCount());
for (i=0; i < dataBase->GetClassCount(); i++)
{
	thickness[i] = -1;
	std::list<int> e;
	eventQueue.push_back(e);
}

for (i = 0; i < eventsCount; i++)
	DrawEvent(dc,i);

for (i=0; i < dataBase->GetClassCount(); i++)
	while (!eventQueue[i].empty())
	{
		DrawLostEvent(dc,eventQueue[i].front());
		eventQueue[i].pop_front();
	}