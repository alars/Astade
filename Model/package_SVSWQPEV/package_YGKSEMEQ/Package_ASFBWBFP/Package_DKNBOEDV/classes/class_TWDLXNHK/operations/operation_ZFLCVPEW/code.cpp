dc.SetFont(GrafFont);

for (std::list<GrafNode*>::iterator it = myGrafNodes.begin(); it != myGrafNodes.end(); it++)
{
	GrafVector g = (*it)->GetPosition();
	(*it)->OnDraw(dc);
}

if (MouseInWindow && selectedNode)
{
	dc.SetBrush(*wxTRANSPARENT_BRUSH);
	dc.SetPen(*wxThePenList->FindOrCreatePen(wxTheColourDatabase->Find("BLACK"),1,wxDOT));
	wxPoint p = ScreenToClient(wxGetMousePosition());
	if (!selectedNode->IsInArea(p))
	{
		GrafVector p2 = selectedNode->GetBorderPoint(GrafVector(p.x,p.y));
		dc.DrawLine(p2.xCoord(),p2.yCoord(),p.x,p.y);
	}
}
