for (std::set<GrafArrow>::iterator it = myAssociation.begin(); it != myAssociation.end(); it++)
{
	if (&((*it).GetEndNode()) == &node)
	{
		myAssociation.erase(it);
		break;
	}
}