int id = ID_JUMP;
AdeElementIterator it;
wxTreeItemId aID = myTree->GetSelection();

AdeComponent* component = dynamic_cast<AdeComponent*>(myTree->GetItem(aID));

if (component==0)
	return;

// Generating the classes
for (it = component->GetFirstBelongingClass(); it != component->end(); ++it)
{
	if (id == event.GetId())
	{
		AdeModelElement* anElement = it.CreateNewElement();
		myTree->ShowNode(anElement->GetFileName());
		delete anElement;
		return;
	}
	id++;
}

// Generating the statecharts
for (it = component->GetFirstBelongingStatechart(); it != component->end(); ++it)
{
	if (id == event.GetId())
	{
		AdeModelElement* anElement = it.CreateNewElement();
		myTree->ShowNode(anElement->GetFileName());
		delete anElement;
		return;
	}
	id++;
}