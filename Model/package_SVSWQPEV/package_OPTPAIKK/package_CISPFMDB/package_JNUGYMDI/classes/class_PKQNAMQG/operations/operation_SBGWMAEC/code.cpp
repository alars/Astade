/* vi: set tabstop=4: */

wxFileConfig ownConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());
wxString PartnerName(GetPartnerName());

if (ownConfig.Read("Astade/PartnerClassname", wxEmptyString) != PartnerName)
{
	ownConfig.Write("Astade/PartnerClassname", PartnerName);
	if (ownConfig.Read("Astade/Name", wxEmptyString) == "relation")
		ownConfig.Write("Astade/Name", wxString("my") + PartnerName);
}

wxString RelationType(ownConfig.Read("Astade/RelationType"));
wxString Implementation(ownConfig.Read("Astade/Implementation"));
wxString Name(ownConfig.Read("Astade/Name"));
wxString Default(ownConfig.Read("Astade/Default"));
if (!Default.empty())
	Default = " = " + Default;

if (RelationType == "ImplementationDependency")
	return "<use> " + PartnerName + " (in .cpp)";

if (RelationType == "SpecificationDependency")
	return "<use> " + PartnerName + " (in .h)";

if (RelationType == "Association")
	return Implementation + " " + Name + Default;

if (RelationType == "Aggregation")
	return Implementation + " " + Name + Default;

if (RelationType == "Composition")
	return Implementation + " " + Name + Default;

if (RelationType == "Generalization")
	return "is a " + PartnerName;

if (RelationType == "Friend")
	return "has friend " + PartnerName;

return "to: " + PartnerName;
