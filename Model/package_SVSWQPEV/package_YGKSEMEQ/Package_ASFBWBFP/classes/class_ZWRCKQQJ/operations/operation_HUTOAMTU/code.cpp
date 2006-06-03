wxPoint p = ScreenToClient(wxGetMousePosition());

if (event.GetId()==ID_ADDACTOR)
	new GrafActor(this,p);

if (event.GetId()==ID_ADDUSECASE)
	new GrafUseCase(this,p);
