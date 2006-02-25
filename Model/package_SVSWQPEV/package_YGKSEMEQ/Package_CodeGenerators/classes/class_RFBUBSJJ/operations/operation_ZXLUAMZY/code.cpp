/* vi: set tabstop=4: */

std::map<wxString,wxString> operationnames;
std::map<wxString,wxString> operationtypes;
std::map<wxString,wxTextFile*> code;
std::set<wxString> operationvirtual;
std::set<wxString> operationabstract;
std::set<wxString> operationconst;
std::set<wxString> operationstatic;

wxFileName operation(source->GetFileName());
operation.AppendDir("operations");

if (wxDir::Exists(operation.GetPath()))
{
	wxDir dir(operation.GetPath());
	wxString filename;

	bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_DIRS);
	while (cont)
	{
		wxFileName FullName = operation;
		FullName.AppendDir(filename);
		FullName.SetFullName("ModelNode.ini");
		const AdeModelElement* pe = AdeModelElement::CreateNewElement(FullName);
		if ((pe->GetType() & ITEM_TYPE_MASK) == ITEM_IS_OPERATION &&
			(pe->GetType() & visibility) == visibility)
		{
			const AdeOperationBase* po = dynamic_cast<const AdeOperationBase*>(pe);
			assert(po);
			if ((po->GetType() & ITEM_IS_DEST) == ITEM_IS_DEST)
				operationnames[FullName.GetFullPath()] = "~" + source->GetName();
			else if ((po->GetType() & ITEM_IS_NORMALOP) != ITEM_IS_NORMALOP)
				operationnames[FullName.GetFullPath()] = source->GetName();
			else
				operationnames[FullName.GetFullPath()] = po->GetName();
			wxString CodingType(po->GetReturntype());
            if (po->IsVirtual())
            {
                operationvirtual.insert(FullName.GetFullPath());
                if (spec)
                    CodingType = "virtual " + CodingType;
            }
            if (po->IsAbstract())
                operationabstract.insert(FullName.GetFullPath());
            if (po->IsStatic())
                operationstatic.insert(FullName.GetFullPath());
            if (po->IsConst())
                operationconst.insert(FullName.GetFullPath());

            operationtypes[FullName.GetFullPath()] = CodingType;
            wxFileName CodeName = FullName;
            CodeName.SetFullName("code.cpp");
            code[FullName.GetFullPath()] = new wxTextFile(CodeName.GetFullPath());
		}
		delete pe;
		cont = dir.GetNext(&filename);
	}
}

std::map<wxString,wxString>::iterator it;

for (it = operationnames.begin(); it != operationnames.end(); ++it)
{
	if (!spec)
	{
		out << std::endl;

		if (source->GetName() == (*it).second)
		{
			// Constructor:
			if (operationtypes[(*it).first].empty())
			{
				out << source->GetName().c_str()
					<< "::" << (*it).second.c_str()
					<< "("  << Paramlist((*it).first).c_str()
					<< ")"  << InitializerList((*it).first).c_str()
					<< std::endl;
				out << "{"  << std::endl;
			}
			else
			{
				out << operationtypes[(*it).first].c_str()
					<< " "  << source->GetName().c_str()
					<< "::" << (*it).second.c_str()
					<< "("  << Paramlist((*it).first).c_str()
					<< ")"  << InitializerList((*it).first).c_str()
					<< std::endl;
				out << "{"  << std::endl;
			}
		}
		else
		{
			wxString Const;
			if (operationconst.find((*it).first) != operationconst.end())
				Const = " const";
			if (operationtypes[(*it).first].empty())
			{
				out << source->GetName().c_str()
					<< "::" << (*it).second.c_str()
					<< "("  << Paramlist((*it).first).c_str()
					<< ")"  << Const.c_str()
					<< std::endl;
				out << "{"  << std::endl;
			}
			else
			{
				out << operationtypes[(*it).first].c_str()
					<< " "  << source->GetName().c_str()
					<< "::" << (*it).second.c_str()
					<< "("  << Paramlist((*it).first).c_str()
					<< ")"  << Const.c_str()
					<< std::endl;
				out << "{"  << std::endl;
			}
		}

		wxTextFile* theCode = code[(*it).first];
		if (theCode->Exists())
			theCode->Open();
		if (theCode->IsOpened() && theCode->GetLineCount() > 0)
		{
			out << "//[" << theCode->GetName() << "]" << std::endl;
			wxString str;
			for (str = theCode->GetFirstLine(); !theCode->Eof(); str = theCode->GetNextLine())
				out << "\t" << str.c_str() << std::endl;
			if (str.size())
				out << "\t" << str.c_str() << std::endl;
        }    
		delete theCode;
		out << "};" << std::endl;
	}
	else
	{
		wxString Static;
		if (operationstatic.find((*it).first) != operationstatic.end())
			Static = "static ";
		wxString Const;
		if (operationconst.find((*it).first) != operationconst.end())
			Const = " const";
		wxString Abstract;
		if (operationabstract.find((*it).first) != operationabstract.end())
			Abstract = " = 0";

		if (operationtypes[(*it).first].empty())
		{
			out << "\t" << Static.c_str()
				<< (*it).second.c_str()
				<< "("  << Paramlist((*it).first).c_str()
				<< ")"  << Const.c_str()
				<< Abstract.c_str()
				<< ";"
				<< std::endl;
		}
		else
		{
			out << "\t" << Static.c_str()
				<< operationtypes[(*it).first].c_str()
				<< " " << (*it).second.c_str()
				<< "(" << Paramlist((*it).first).c_str()
				<< ")" << Const.c_str()
				<< Abstract.c_str()
				<< ";"
				<< std::endl;
		}
	}
}
