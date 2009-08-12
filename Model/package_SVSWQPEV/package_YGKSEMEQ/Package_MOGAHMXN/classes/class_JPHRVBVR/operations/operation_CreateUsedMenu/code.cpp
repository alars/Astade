wxMenu* aSubUp = new wxMenu(wxEmptyString);

AdeElementIterator it;
std::map<wxString,int> menuItems;

for (it = element.GetFirstComponent(); it != AdeElementIterator(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();

	int type = anElement->GetType();
	if ((type & ITEM_TYPE_MASK) == ITEM_IS_COMPONENT)
		menuItems[anElement->GetName()] = -1;
	delete anElement;
}

for (std::map<wxString,int>::iterator iter = menuItems.begin(); iter != menuItems.end(); iter++)
	aSubUp->Append((*iter).second, (*iter).first);

return aSubUp;
