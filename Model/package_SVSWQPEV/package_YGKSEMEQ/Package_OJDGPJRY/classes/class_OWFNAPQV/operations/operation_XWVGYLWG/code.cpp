if (m_MouseOver)
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("DARK GREY"),1,wxSOLID));

int w,h;
GetSize(&w,&h);

wxPoint points[4];

points[0].x = myPosition.x-(w/2);
points[0].y = myPosition.y;

points[1].x = myPosition.x;
points[1].y = myPosition.y-(h/2);

points[2].x = myPosition.x+(w/2);
points[2].y = myPosition.y;

points[3].x = myPosition.x;
points[3].y = myPosition.y+(h/2);

dc.DrawPolygon(4, points);