if (relationType==hasAssociationID)
{
	GrafUseCase* aUseCase = dynamic_cast<GrafUseCase*>(&destination);
	if (aUseCase)
	{
		GrafArrow* anArrow = new GrafArrow(*this,*aUseCase,ARROWHEADNONE,"",wxSOLID,"red");
		myAssociation.insert(myAssociation.begin(),anArrow);
		m_Parent->DeclareEdge(anArrow);
		m_Parent->NotifyModification();
	}
}

if (relationType==generalisationID)
{
	GrafActor* aActor = dynamic_cast<GrafActor*>(&destination);
	if (aActor)
	{
		GrafArrow* anArrow = new GrafArrow(*this,*aActor,ARROWHEADSOLID,"",wxSOLID,"blue");
		mySuperclass.insert(mySuperclass.begin(),anArrow);
		m_Parent->DeclareEdge(anArrow);
		m_Parent->NotifyModification();
	}
}