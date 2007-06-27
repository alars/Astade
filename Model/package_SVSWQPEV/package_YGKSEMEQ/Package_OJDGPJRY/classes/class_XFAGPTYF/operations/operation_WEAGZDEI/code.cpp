dc.SetBrush(*wxWHITE);

if (m_MouseOver)
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
else
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("DARK GREY"),1,wxSOLID));

int w,h;
GetSize(&w,&h);

dc.DrawRoundedRectangle(myPosition.x-(w/2),
						myPosition.y-(h/2),
						w,h,15);