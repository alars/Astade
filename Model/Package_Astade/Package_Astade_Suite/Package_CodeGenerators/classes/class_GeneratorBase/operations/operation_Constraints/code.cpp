//~~ void Constraints(std::ofstream& out, const AdeOperationBase& op) [GeneratorBase] ~~

std::list<AdeParameter*> parameterlist = op.Parameterlist();
std::list<wxString> constraints;

wxString constraint = op.GetConstraint();
if (!constraint.empty())
	constraints.push_back(wxS("\tCONSTRAINT(") + constraint + wxS(");"));

for (std::list<AdeParameter*>::iterator it = parameterlist.begin(); it != parameterlist.end(); ++it)
{
	wxString constraint = (*it)->GetConstraint();
	if (!constraint.empty())
		constraints.push_back(wxS("\tCONSTRAINT(") + constraint + wxS(");"));
	delete *it;
}

wxFileName attributes(source->GetFileName());
attributes.AppendDir(wxS("attributes"));

if (wxDir::Exists(attributes.GetPath()))
{
	wxDir dir(attributes.GetPath());
	wxString filename;

	bool cont = dir.GetFirst(&filename, wxS("*.ini"));
	while (cont)
	{
		wxFileName FullName(attributes);
		FullName.SetFullName(filename);
		const AdeModelElement* pe = AdeModelElement::CreateNewElement(FullName);

		wxString constraint = pe->GetConstraint();
		if (!constraint.empty())
			constraints.push_back(wxS("\tCONSTRAINT(") + constraint + wxS(");"));

		delete pe;
		cont = dir.GetNext(&filename);
	}
}

if (!constraints.empty())
{
	out << std::endl << "#ifdef CONSTRAINT" << std::endl;
	
	for (std::list<wxString>::iterator it = constraints.begin(); it != constraints.end(); ++it)
		out << (*it) << std::endl;
	
	out << "#endif" << std::endl << std::endl;
}
