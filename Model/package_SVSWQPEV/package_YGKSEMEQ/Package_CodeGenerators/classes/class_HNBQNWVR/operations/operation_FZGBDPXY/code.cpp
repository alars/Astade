/* vi: set tabstop=4: */

std::map<wxString, const AdeOperationBase*, AdeStringCompare> ops;

wxFileName op(source->GetFileName());
op.AppendDir("operations");

if (wxDir::Exists(op.GetPath()))
{
	wxDir dir(op.GetPath());
	wxString filename;

	bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_DIRS);
	while (cont)
	{
		wxFileName FullName = op;
		FullName.AppendDir(filename);
		FullName.SetFullName("ModelNode.ini");
		const AdeModelElement* pe = AdeModelElement::CreateNewElement(FullName);
		if ((pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_OPERATION &&
			(pe->GetType() & visibility) == visibility)
		{
			const AdeOperationBase* po = dynamic_cast<const AdeOperationBase*>(pe);
			assert(po);
			ops[po->GetSignature()] = po;
		}
		else
			delete pe;
		cont = dir.GetNext(&filename);
	}
}

std::map<wxString, const AdeOperationBase*>::iterator it;

for (it = ops.begin(); it != ops.end(); ++it)
{
	if (spec)
	{
		specOperation(out, *it->second);
	}
	else
	{
		if (it->second->IsInline() == inlines)
			codeOperation(out, *it->second);
	}
}
