//~~ wxString InitializerList(const AdeOperationBase* po) [CGenerator] ~~

wxString paramlist;
if ((po->GetType() & (ITEM_IS_NORMALOP|ITEM_IS_DEST)) == 0)
{
	const AdeConstructor* pc = dynamic_cast<const AdeConstructor*>(po);
	assert(pc);
	paramlist = pc->GetInitializers();

	if (!paramlist.empty())
		paramlist = wxS("\t") + paramlist + wxS("\n");

	std::list<wxString>::iterator it;

	for (it = AttributeList.begin(); it != AttributeList.end(); ++it)
	{
		if (!memberDefaults[*it].empty())
            paramlist += wxS("\tme->") + *it + wxS(" = ") + memberDefaults[*it] + wxS(";\n");
	}
}
return paramlist;
