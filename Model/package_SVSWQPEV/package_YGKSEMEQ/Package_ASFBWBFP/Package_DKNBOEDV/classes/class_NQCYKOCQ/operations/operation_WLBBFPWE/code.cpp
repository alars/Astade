for (std::set<GrafArrow*>::iterator it = myAssociation.begin(); it != myAssociation.end(); it++)
{
	if (&((*it)->GetEndNode()) == &node)
	{
		delete *it;
		myAssociation.erase(it);
		break;
	}
}