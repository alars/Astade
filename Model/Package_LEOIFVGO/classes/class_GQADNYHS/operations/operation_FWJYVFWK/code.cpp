SetVirtualSize(dataBase->GetGraphWidth(), dataBase->GetGraphHight());

wxPaintDC dc( this );
PrepareDC( dc );

dc.SetFont(wxFont(8, wxFONTFAMILY_SWISS , wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL ));

DrawClassLines(dc);

int eventsCount = dataBase->GetEventsCount();

for (int i = 0; i < eventsCount; i++)
	DrawEvent(dc,i);
