for (std::set<GrafArrow>::iterator it = myExtend.begin(); it != myExtend.end(); it++)
{
	if (&((*it).GetEndNode()) == &node)
	{
		myExtend.erase(it);
		break;
	}
}

for (std::set<GrafArrow>::iterator it = myInclude.begin(); it != myInclude.end(); it++)
{
	if (&((*it).GetEndNode()) == &node)
	{
		myInclude.erase(it);
		break;
	}
}

for (std::set<GrafArrow>::iterator it = mySuperclass.begin(); it != mySuperclass.end(); it++)
{
	if (&((*it).GetEndNode()) == &node)
	{
		mySuperclass.erase(it);
		break;
	}
}