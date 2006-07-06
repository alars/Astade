MouseInWindow = false;

for (std::set<GrafNode*>::iterator it = myGrafNodes.begin(); it != myGrafNodes.end(); it++)
	(*it)->SetMouseOver(false);

if (selectedNode)
{
	selectedNode = NULL;
	Refresh();
}