int count = deleteExtentionID;
for (std::set<GrafArrow*>::iterator it = myExtend.begin(); it != myExtend.end(); it++)
{
	if (event.GetId()==count)
	{
		delete *it;
		myExtend.erase(it);
		m_Parent->NotifyModification();
		return;
	}
	++count;
}

count = deleteIncludeID;
for (std::set<GrafArrow*>::iterator it = myInclude.begin(); it != myInclude.end(); it++)
{
	if (event.GetId()==count)
	{
		delete *it;
		myInclude.erase(it);
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