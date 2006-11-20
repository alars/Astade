dc.SetFont(wxFont(8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

int eventsCount = dataBase->GetEventsCount();

int i;

eventQueue.clear();
eventQueue.reserve(dataBase->GetClassCount());

thickness.reserve(dataBase->GetClassCount());
for (i = 0; i < dataBase->GetClassCount(); i++)
{
	thickness[i] = -1;
	std::list<int> e;
	eventQueue.push_back(e);
}

// Calculate class box sizes
for (i = 0; i < dataBase->GetClassCount(); i++)
{
	wxString name = dataBase->GetClassName(i);

	int pos = name.Find(':');
	if (pos >= 0 && pos != name.Find("::"))
		dc.SetFont(objectFont);
	else
		dc.SetFont(classFont);

	wxCoord w,h;
	wxCoord w2, h2;
	wxString name2;

	if (name.Find("\\n")!=-1)
	{
		int pos = name.Find("\\n");
		name2 = name.Mid(pos+2);
		name = name.Left(pos);

		dc.GetTextExtent(name, &w, &h);
		dc.GetTextExtent(name2, &w2, &h2);
		if (w2>w)
			w = w2;
	}
	else
	{
		dc.GetTextExtent(name, &w, &h);
	}

	int width = w+10;
	if (width < 80)
		width = 80;
	dataBase->SetClassBoxWidth(i, width);
}

dc.SetFont(normalFont);

// Now all the events
for (i = 0; i < eventsCount; i++)
	DrawEvent(dc, i);

for (i = 0; i < dataBase->GetClassCount(); i++)
	while (!eventQueue[i].empty())
	{
		DrawLostEvent(dc, eventQueue[i].front());
		eventQueue[i].pop_front();
	}
