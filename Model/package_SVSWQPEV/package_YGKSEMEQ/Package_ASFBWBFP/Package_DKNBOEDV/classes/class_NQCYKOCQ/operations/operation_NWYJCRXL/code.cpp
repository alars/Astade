int count = deleteAssiciationID;
for (std::set<GrafNode*>::iterator it = myAssociation.begin(); it != myAssociation.end(); it++)
{
	if (event.GetId()==count)
	{
		myAssociation.erase(it);
		m_Parent->NotifyModification();
		return;
	}
	++count;
}