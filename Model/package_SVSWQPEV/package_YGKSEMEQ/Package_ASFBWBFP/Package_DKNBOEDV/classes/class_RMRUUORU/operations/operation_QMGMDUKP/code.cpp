for (std::set<GrafArrow*>::iterator it = myExtend.begin(); it != myExtend.end(); it++)
{
	if (&((*it)->GetEndNode()) == &node)
	{
		delete *it;
		myExtend.erase(it);
		break;
	}
}

for (std::set<GrafArrow*>::iterator it = myInclude.begin(); it != myInclude.end(); it++)
{
	if (&((*it)->GetEndNode()) == &node)
	{
		delete *it;
		myInclude.erase(it);
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