if (m_MouseOver)
{
	dc.SetBrush(*wxLIGHT_GREY);
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("RED"),2,wxSOLID));
}
else
{
	dc.SetBrush(*wxLIGHT_GREY);
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("DARK GREY"),1,wxSOLID));
}

int w,h;
GetSize(&w,&h);
dc.DrawEllipse((-w/2)+m_Position.xCoord(),(-h/2)+m_Position.yCoord(),w,h);

wxString label = myLabel->GetLineText(0);
dc.GetTextExtent(label,&w,&h);
dc.DrawText(label,m_Position.xCoord()-(w/2),m_Position.yCoord()-(h+(h/2)));

label = myLabel->GetLineText(1);
dc.GetTextExtent(label,&w,&h);
dc.DrawText(label,m_Position.xCoord()-(w/2),m_Position.yCoord()-(h/2));

label = myLabel->GetLineText(2);
dc.GetTextExtent(label,&w,&h);
dc.DrawText(label,m_Position.xCoord()-(w/2),m_Position.yCoord()+(h/2));

for (std::set<GrafNode*>::iterator it = mySuperclass.begin(); it != mySuperclass.end(); it++)
{
	GrafVector p1 = GetPosition();
	GrafVector p2 = (*it)->GetPosition();

	GrafVector r1 = GetBorderPoint(p2);
	GrafVector r2 = (*it)->GetBorderPoint(p1);

	dc.SetBrush(*wxWHITE);

	if (m_MouseOver)
		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"),2,wxSOLID));
	else
		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"),1,wxSOLID));

	DrawArrow(dc,r1.xCoord(),r1.yCoord(),r2.xCoord(),r2.yCoord(),ARROWHEADSOLID,"");
}

for (std::set<GrafNode*>::iterator it = myExtent.begin(); it != myExtent.end(); it++)
{
	GrafVector p1 = GetPosition();
	GrafVector p2 = (*it)->GetPosition();

	GrafVector r1 = GetBorderPoint(p2);
	GrafVector r2 = (*it)->GetBorderPoint(p1);

	dc.SetBrush(*wxWHITE);

	if (m_MouseOver)
		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"),2,wxSHORT_DASH));
	else
		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"),1,wxSHORT_DASH));

	DrawArrow(dc,r1.xCoord(),r1.yCoord(),r2.xCoord(),r2.yCoord(),ARROWHEADVEE,"<<extend>>");
}

for (std::set<GrafNode*>::iterator it = myInclude.begin(); it != myInclude.end(); it++)
{
	GrafVector p1 = GetPosition();
	GrafVector p2 = (*it)->GetPosition();

	GrafVector r1 = GetBorderPoint(p2);
	GrafVector r2 = (*it)->GetBorderPoint(p1);

	dc.SetBrush(*wxWHITE);

	if (m_MouseOver)
		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"),2,wxSHORT_DASH ));
	else
		dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLUE"),1,wxSHORT_DASH ));

	DrawArrow(dc,r1.xCoord(),r1.yCoord(),r2.xCoord(),r2.yCoord(),ARROWHEADVEE,"<<include>>");
}
