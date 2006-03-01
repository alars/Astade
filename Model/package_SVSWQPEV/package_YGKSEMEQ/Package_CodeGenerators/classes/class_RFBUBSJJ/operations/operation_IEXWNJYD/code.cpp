/* vi: set tabstop=4: */

wxString paramlist;
if ((po->GetType() & (ITEM_IS_NORMALOP|ITEM_IS_DEST)) == 0)
{
	const AdeConstructor* pc = dynamic_cast<const AdeConstructor*>(po);
	assert(pc);
	paramlist = pc->GetInitializers();

	if (!paramlist.empty())
		paramlist = " :\n\t" + paramlist;

	while (!AttributeList.empty())
	{
		if (!memberDefaults[AttributeList.front()].empty())
		{
			if (paramlist.empty())
				paramlist = " :\n\t" + AttributeList.front() + "(" + memberDefaults[AttributeList.front()] + ")";
			else
				paramlist = paramlist + ",\n\t" + AttributeList.front() + "(" + memberDefaults[AttributeList.front()] + ")";
		}
		AttributeList.pop_front();
	}
}
return paramlist;
