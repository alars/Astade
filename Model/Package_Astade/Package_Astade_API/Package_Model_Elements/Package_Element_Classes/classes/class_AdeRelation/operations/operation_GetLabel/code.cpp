//~~ wxString GetLabel() [AdeRelation] ~~
wxString PartnerName(GetPartnerName());

if (myConfig->Read(wxS("Astade/PartnerClassname"), wxEmptyString) != PartnerName)
{
    myConfig->Write(wxS("Astade/PartnerClassname"), PartnerName);
    if (myConfig->Read(wxS("Astade/Name"), wxEmptyString) == wxS("relation"))
        myConfig->Write(wxS("Astade/Name"), wxS("my") + PartnerName);
    myConfig->Flush();
}

wxString RelationType(myConfig->Read(wxS("Astade/RelationType")));
wxString Implementation(myConfig->Read(wxS("Astade/Implementation")));
wxString Name(myConfig->Read(wxS("Astade/Name")));
wxString Default(myConfig->Read(wxS("Astade/Default")));
wxString Template(myConfig->Read(wxS("Astade/Template")));

if (!Default.empty())
    Default = wxS(" = ") + Default;

if (RelationType == wxS("ImplementationDependency"))
    return wxS("<use> ") + PartnerName + wxS(" (in .cpp)");

if (RelationType == wxS("SpecificationDependency"))
    return wxS("<use> ") + PartnerName + wxS(" (in .h)");

if (RelationType == wxS("Association"))
    return Implementation + wxS(" ") + Name + Default;

if (RelationType == wxS("Aggregation"))
    return Implementation + wxS(" ") + Name + Default;

if (RelationType == wxS("Composition"))
    return Implementation + wxS(" ") + Name + Default;

if (RelationType == wxS("Generalization"))
{
    if (!Template.empty())
        return wxS("is a ") + PartnerName + wxS("<") + Template + wxS(">") + Default;
    else
        return wxS("is a ") + PartnerName + Default;
}

if (RelationType == wxS("Friend"))
    return wxS("has friend ") + PartnerName;

return wxS("to: ") + PartnerName;
