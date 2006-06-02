for (std::list<GrafNode*>::iterator it = myGrafNodes.begin(); it != myGrafNodes.end(); it++)
{
	GrafVector g = (*it)->GetPosition();
	dc.SetDeviceOrigin(g.xCoord(),g.yCoord());
	(*it)->OnDraw(dc);
}