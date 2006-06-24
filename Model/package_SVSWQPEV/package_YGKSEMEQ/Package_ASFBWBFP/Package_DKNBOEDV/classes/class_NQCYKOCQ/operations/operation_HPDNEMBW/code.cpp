GrafUseCase* aUseCase = dynamic_cast<GrafUseCase*>(&destination);
if (aUseCase)
{
	myAssociation.insert(myAssociation.begin(),GrafArrow(*this,*aUseCase,ARROWHEADNONE,"",wxSOLID,"red"));
	m_Parent->NotifyModification();
}