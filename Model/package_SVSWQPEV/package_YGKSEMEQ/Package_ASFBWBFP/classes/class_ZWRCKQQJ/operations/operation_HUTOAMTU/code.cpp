wxPoint p = ScreenToClient(wxGetMousePosition());

if (event.GetId()==ID_ADDACTOR)
	GrafNodeRegister::GetInstance().Create("GrafActor",this,p);

if (event.GetId()==ID_ADDUSECASE)
	GrafNodeRegister::GetInstance().Create("GrafUseCase",this,p);
