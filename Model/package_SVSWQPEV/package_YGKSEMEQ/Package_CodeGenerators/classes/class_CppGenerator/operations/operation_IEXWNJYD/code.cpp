/* vi: set tabstop=4: */

wxString paramlist;
if ((po->GetType() & (ITEM_IS_NORMALOP|ITEM_IS_DEST)) == 0)
{
	const AdeConstructor* pc = dynamic_cast<const AdeConstructor*>(po);
	assert(pc);
	paramlist = pc->GetInitializers();

	if (!paramlist.empty())
		paramlist = " :\n\t" + paramlist;

	std::list<wxString>::iterator it;

	for (it = AttributeList.begin(); it != AttributeList.end(); ++it)
	{
		if (!memberDefaults[*it].empty())
		{
			if (paramlist.empty())
				paramlist = " :\n\t" + *it + "(" + memberDefaults[*it] + ")";
			else
				paramlist = paramlist + ",\n\t" + *it + "(" + memberDefaults[*it] + ")";
		}
	}
}
return paramlist;
