dc.SetBrush(*wxWHITE);

if (m_MouseOver)
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("Blue"),1,wxSOLID));

int w,h;
GetSize(&w,&h);

dc.DrawLine(myPosition.x,myPosition.y-(h/2),myPosition.x,myPosition.y+(h/2));
dc.DrawLine(myPosition.x,myPosition.y+(h/2),myPosition.x-(w/2),myPosition.y+(h/2)-15);
dc.DrawLine(myPosition.x,myPosition.y+(h/2),myPosition.x+(w/2),myPosition.y+(h/2)-15);
