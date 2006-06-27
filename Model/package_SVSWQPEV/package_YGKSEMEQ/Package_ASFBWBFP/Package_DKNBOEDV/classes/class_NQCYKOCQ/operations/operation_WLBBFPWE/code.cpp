for (std::set<GrafArrow*>::iterator it = myAssociation.begin(); it != myAssociation.end(); it++)
{
	if (&((*it)->GetEndNode()) == &node)
	{
		delete *it;
		myAssociation.erase(it);
		break;
	}
}

for (std::set<GrafArrow*>::iterator it = mySuperclass.begin(); it != mySuperclass.end(); it++)
{
	if (&((*it)->GetEndNode()) == &node)
	{
		delete *it;
		mySuperclass.erase(it);
		break;
	}
}