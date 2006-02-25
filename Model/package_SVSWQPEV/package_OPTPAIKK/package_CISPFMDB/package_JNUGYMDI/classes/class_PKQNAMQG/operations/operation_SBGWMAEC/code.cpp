wxFileName PartnerFile = GetPartnerFile();
int i = PartnerFile.GetDirCount();
PartnerFile.RemoveDir(i);
PartnerFile.RemoveDir(i-1);
PartnerFile.SetFullName("ModelNode.ini");

wxFileConfig thePartnerConfig(wxEmptyString, wxEmptyString, PartnerFile.GetFullPath());
wxString PartnerName = thePartnerConfig.Read("Astade/Name");

wxFileConfig ownConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());

if (ownConfig.Read("Astade/PartnerClassname", wxEmptyString) != PartnerName)
{
	ownConfig.Write("Astade/PartnerClassname", PartnerName);
	if (ownConfig.Read("Astade/Name", wxEmptyString) == "relation")
		ownConfig.Write("Astade/Name", wxString("my") + PartnerName);
}

wxString RelationType = ownConfig.Read("Astade/RelationType");
wxString Implementation = ownConfig.Read("Astade/Implementation");
wxString Name = ownConfig.Read("Astade/Name");

if (RelationType == "ImplementationDependency")
	return "<use> " + PartnerName + " (in .cpp)";

if (RelationType == "SpecificationDependency")
	return "<use> " + PartnerName + " (in .h)";

if (RelationType == "Association")
	return Implementation + " " + Name;

if (RelationType == "Aggregation")
	return Implementation + " " + Name;

if (RelationType == "Composition")
	return Implementation + " " + Name;

if (RelationType == "Generalization")
	return "is a " + PartnerName;

return "to: " + PartnerName;
