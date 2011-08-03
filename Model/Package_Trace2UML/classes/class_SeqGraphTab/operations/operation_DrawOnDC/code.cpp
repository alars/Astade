//~~ void DrawOnDC(cairo_t* cr, wxDC& dc, bool clip = false) [SeqGraphTab] ~~
int eventsCount = dataBase->GetEventsCount();

eventQueue.clear();
eventQueue.reserve(dataBase->GetClassCount());

while ((int)thickness.size() < dataBase->GetClassCount())
    thickness.push_back(0);

int i;
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

	double w;

	int pos = name.Find(wxS("\\n"));
	if (pos >= 0)
	{
        cairo_text_extents_t theExtents;
        cairo_text_extents(cr, name.Mid(pos + 2).c_str(), &theExtents);
        w = theExtents.width;

        cairo_text_extents(cr, name.Left(pos).c_str(), &theExtents);
        
        if (theExtents.width > w)
			w = theExtents.width;
	}
	else
	{
        cairo_text_extents_t theExtents;
        cairo_text_extents(cr, name.c_str(), &theExtents);
        w = theExtents.width;
	}

	int width = w + 8;
	if (width < 70)
		width = 70;
	dataBase->SetClassBoxWidth(i, width);
}

// Now all the events
for (i = 0; i < eventsCount; i++)
	DrawEvent(cr, i, clip);

for (i = 0; i < dataBase->GetClassCount(); i++)
	while (!eventQueue[i].empty())
	{
		DrawLostEvent(cr, eventQueue[i].front());
		eventQueue[i].pop_front();
	}
