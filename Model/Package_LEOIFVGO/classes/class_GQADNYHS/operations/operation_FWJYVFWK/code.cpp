SetVirtualSize(dataBase->GetGraphWidth(), dataBase->GetGraphHight());

wxPaintDC dc( this );
PrepareDC( dc );

dc.SetFont(wxFont(8, wxFONTFAMILY_SWISS , wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL ));

int eventsCount = dataBase->GetEventsCount();

int i;

thickness.reserve(dataBase->GetClassCount());
for (i=0; i < dataBase->GetClassCount(); i++)
	thickness[i] = -1;

for (i = 0; i < eventsCount; i++)
	DrawEvent(dc,i);
