AdeModelElement* element1 = GetItem(item1);
AdeModelElement* element2 = GetItem(item2);

int type1 = element1->GetType();
int type2 = element2->GetType();

if (type1 != type2)
	return type1-type2;

return wxStrcmp(element1->GetName(), element2->GetName());

