for (std::set<GrafNode*>::iterator it = myGrafNodes.begin(); it != myGrafNodes.end(); it++)
{
	if ((*it)->IsInArea(event.GetPosition()))
	{
		(*it)->ContextMenu();
		return;
	}
}
ContextMenu();