if (relationType==hasAssociationID)
{
	GrafUseCase* aUseCase = dynamic_cast<GrafUseCase*>(&destination);
	if (aUseCase)
	{
		myAssociation.insert(myAssociation.begin(),new GrafArrow(*this,*aUseCase,ARROWHEADNONE,"",wxSOLID,"red"));
		m_Parent->NotifyModification();
	}
}

if (relationType==generalisationID)
{
	GrafActor* aActor = dynamic_cast<GrafActor*>(&destination);
	if (aActor)
	{
		mySuperclass.insert(mySuperclass.begin(),new GrafArrow(*this,*aActor,ARROWHEADSOLID,"",wxSOLID,"blue"));
		m_Parent->NotifyModification();
	}
}