wxMenu* aSubUp = new wxMenu(wxEmptyString);

int id = ID_JUMP;
AdeElementIterator it;

// Generating the classes
for (it = component.GetFirstBelongingClass(); it != component.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	aSubUp->Append(id++, anElement->GetName());
	delete anElement;
	if (id >= ID_JUMPMAX)
		return aSubUp;
}

// Generating the statecharts
for (it = component.GetFirstBelongingStatechart(); it != component.end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	aSubUp->Append(id++, anElement->GetName());
	delete anElement;
	if (id >= ID_JUMPMAX)
		return aSubUp;
}

return aSubUp;
