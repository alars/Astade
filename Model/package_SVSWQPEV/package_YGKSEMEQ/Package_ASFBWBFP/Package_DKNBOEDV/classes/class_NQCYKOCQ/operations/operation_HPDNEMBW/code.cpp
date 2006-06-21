GrafUseCase* aUseCase = dynamic_cast<GrafUseCase*>(&destination);
if (aUseCase)
{
	myAssociation.insert(myAssociation.begin(),&destination);
	m_Parent->NotifyModification();
}