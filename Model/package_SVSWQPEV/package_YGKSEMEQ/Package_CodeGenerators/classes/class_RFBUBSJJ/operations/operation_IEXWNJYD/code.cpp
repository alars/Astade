/* vi: set tabstop=4: */

wxString paramlist;
const AdeModelElement* pe = AdeModelElement::CreateNewElement(Operationpath);
if ((pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_OPERATION &&
	(pe->GetType() & (ITEM_IS_DEST|ITEM_IS_NORMALOP)) == 0)
{
	const AdeConstructor* pc = dynamic_cast<const AdeConstructor*>(pe);
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
delete pe;
return paramlist;
