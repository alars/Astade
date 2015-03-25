//~~ int OnCompareItems(const wxTreeItemId& item1, const wxTreeItemId& item2) [AstadeTree] ~~
AdeModelElement* element1 = GetItem(item1);
AdeModelElement* element2 = GetItem(item2);

int type1 = element1->GetType();
int type2 = element2->GetType();

if (type1 != type2)
	return type1 - type2;

return element1->GetSortName().CmpNoCase(element2->GetSortName());
