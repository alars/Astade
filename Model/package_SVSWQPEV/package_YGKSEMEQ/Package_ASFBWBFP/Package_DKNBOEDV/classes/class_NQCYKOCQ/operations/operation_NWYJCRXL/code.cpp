int count = deleteAssiciationID;
for (std::set<GrafArrow*>::iterator it = myAssociation.begin(); it != myAssociation.end(); it++)
{
	if (event.GetId()==count)
	{
		GrafArrow* aArrow = *it;
		myAssociation.erase(it);
		delete aArrow;
		m_Parent->NotifyModification();
		return;
	}
	++count;
}

count = deleteSpecialisationID;
for (std::set<GrafArrow*>::iterator it = mySuperclass.begin(); it != mySuperclass.end(); it++)
{
	if (event.GetId()==count)
	{
		delete *it;
		mySuperclass.erase(it);
		m_Parent->NotifyModification();
		return;
	}
	++count;
}