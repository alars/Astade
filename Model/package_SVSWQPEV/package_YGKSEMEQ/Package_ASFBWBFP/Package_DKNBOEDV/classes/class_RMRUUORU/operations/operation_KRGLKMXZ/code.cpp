int count = deleteExtentionID;
for (std::set<GrafNode*>::iterator it = myExtent.begin(); it != myExtent.end(); it++)
{
	if (event.GetId()==count)
	{
		myExtent.erase(it);
		m_Parent->NotifyModification();
		return;
	}
	++count;
}

count = deleteIncludeID;
for (std::set<GrafNode*>::iterator it = myInclude.begin(); it != myInclude.end(); it++)
{
	if (event.GetId()==count)
	{
		myInclude.erase(it);
		m_Parent->NotifyModification();
		return;
	}
	++count;
}

count = deleteSpecialisationID;
for (std::set<GrafNode*>::iterator it = mySuperclass.begin(); it != mySuperclass.end(); it++)
{
	if (event.GetId()==count)
	{
		mySuperclass.erase(it);
		m_Parent->NotifyModification();
		return;
	}
	++count;
}