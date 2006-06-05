for (std::list<GrafNode*>::iterator it = myGrafNodes.begin(); it != myGrafNodes.end(); it++)
{
	GrafVector g = (*it)->GetPosition();
	(*it)->OnDraw(dc);
}

if (selectedNode)
{
	wxPoint p = ScreenToClient(wxGetMousePosition());
	GrafVector p2 = selectedNode->GetBorderPoint(GrafVector(p.x,p.y));
	dc.DrawLine(p2.xCoord(),p2.yCoord(),p.x,p.y);
}
