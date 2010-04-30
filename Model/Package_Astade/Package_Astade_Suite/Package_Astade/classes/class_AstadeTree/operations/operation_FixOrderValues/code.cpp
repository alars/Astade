// We do this for parameters and attributes only
if ((dynamic_cast<AdeParameter*>(GetItem(aID)) == 0) && (dynamic_cast<AdeAttribute*>(GetItem(aID)) == 0))
	return;

wxTreeItemId search = aID;

while (GetPrevSibling(search).IsOk())
	search = GetPrevSibling(search);

unsigned char count = 1;

while (search.IsOk())
{
	GetItem(search)->SetOrderValue(count++);
	search = GetNextSibling(search);
}
