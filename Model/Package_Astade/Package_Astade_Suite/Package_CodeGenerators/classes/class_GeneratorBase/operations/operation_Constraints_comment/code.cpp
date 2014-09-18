//~~ void Constraints_comment(std::ofstream& out, const AdeOperationBase& op) [GeneratorBase] ~~

std::list<AdeParameter*> parameterlist = op.Parameterlist();
std::list<wxString> constraints;

wxString constraint = op.GetConstraint();
if (!constraint.empty())
    constraints.push_back(wxS("@pre ") + constraint);

for (std::list<AdeParameter*>::iterator it = parameterlist.begin(); it != parameterlist.end(); ++it)
{
    wxString constraint = (*it)->GetConstraint();
    if (!constraint.empty())
        constraints.push_back(wxS("@pre ") + constraint);
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
            constraints.push_back(wxS("@pre ") + constraint);

        delete pe;
        cont = dir.GetNext(&filename);
    }
}

if (!constraints.empty())
{
    for (std::list<wxString>::iterator it = constraints.begin(); it != constraints.end(); ++it)
        out << it->utf8_str() << std::endl;
}
