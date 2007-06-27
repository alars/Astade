dc.SetBrush(*wxWHITE);

if (m_MouseOver)
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("DARK GREY"),1,wxSOLID));

int w,h;
GetSize(&w,&h);

dc.DrawCircle(myPosition,w/2);

dc.SetBrush(*wxBLUE);
dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"),2,wxSOLID));

dc.DrawCircle(myPosition,w/3);