wxPoint position = myPosition;
int predDist = 0;

for (std::list<ACNode*>::iterator it = myNodes.begin(); it != myNodes.end(); it++)
{
	int nodeW, nodeH;
	(*it)->GetSize(&nodeW, &nodeH);

	wxPoint dist = wxPoint(0,(nodeH/2) + (predDist/2));
	position += dist;
	predDist = nodeH;

	(*it)->SetPosition(position);
}