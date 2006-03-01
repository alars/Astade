/* vi: set tabstop=4: */

std::map<wxString,wxString> opnames;
std::map<wxString,wxString> optypes;
std::map<wxString,wxTextFile*> code;
std::set<wxString> opstatic;
std::set<wxString> opinline;
std::set<wxString> opvirtual;
std::set<wxString> opconst;
std::set<wxString> opabstract;

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
			if ((po->GetType() & ITEM_IS_DEST) == ITEM_IS_DEST)
				opnames[FullName.GetFullPath()] = "~" + source->GetName();
			else if ((po->GetType() & ITEM_IS_NORMALOP) != ITEM_IS_NORMALOP)
				opnames[FullName.GetFullPath()] = source->GetName();
			else
				opnames[FullName.GetFullPath()] = po->GetName();
            if (po->IsVirtual())
                opvirtual.insert(FullName.GetFullPath());
            if (po->IsAbstract())
                opabstract.insert(FullName.GetFullPath());
            if (po->IsStatic())
                opstatic.insert(FullName.GetFullPath());
            if (po->IsConst())
                opconst.insert(FullName.GetFullPath());
            if (po->IsInline())
                opinline.insert(FullName.GetFullPath());
            optypes[FullName.GetFullPath()] = po->GetReturntype();
            wxFileName CodeName = FullName;
            CodeName.SetFullName("code.cpp");
            code[FullName.GetFullPath()] = new wxTextFile(CodeName.GetFullPath());
		}
		delete pe;
		cont = dir.GetNext(&filename);
	}
}

std::map<wxString,wxString>::iterator it;

for (it = opnames.begin(); it != opnames.end(); ++it)
{
	if (!spec)
	{
		bool isInline   = opinline.find((*it).first)   != opinline.end();
		bool isConst    = opconst.find((*it).first)    != opconst.end();
		bool isAbstract = opabstract.find((*it).first) != opabstract.end();
		if (isInline == inlines)
			codeOperation(out, (*it).first, (*it).second, optypes[(*it).first], code[(*it).first], isInline, isConst, isAbstract);
		delete code[(*it).first];
	}
	else
	{
		bool isStatic   = opstatic.find((*it).first)   != opstatic.end();
		bool isInline   = opinline.find((*it).first)   != opinline.end();
		bool isVirtual  = opvirtual.find((*it).first)  != opvirtual.end();
		bool isConst    = opconst.find((*it).first)    != opconst.end();
		bool isAbstract = opabstract.find((*it).first) != opabstract.end();
		specOperation(out, (*it).first, (*it).second, optypes[(*it).first], isStatic, isInline, isVirtual, isConst, isAbstract);
	}
}
