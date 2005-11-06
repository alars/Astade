wxFileName PartnerFile = GetPartnerFile();
int i = PartnerFile.GetDirCount();
PartnerFile.RemoveDir(i);
PartnerFile.RemoveDir(i-1);
PartnerFile.SetFullName("ModelNode.ini");

wxFileConfig thePartnerConfig(wxEmptyString,wxEmptyString,PartnerFile.GetFullPath());
wxString PartnerName = thePartnerConfig.Read("Astade/Name");

wxFileConfig ownConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());
ownConfig.Write("Astade/PartnerClassname",PartnerName);
wxString RelationType = ownConfig.Read("Astade/RelationType");
wxString Implementation = ownConfig.Read("Astade/Implementation");
wxString Name = ownConfig.Read("Astade/Name");

if (RelationType=="ImplementationDependency")
	return "<uses> " + PartnerName + " (in .cpp)";

if (RelationType=="SpecificationDependency")
	return "<uses> " + PartnerName + " (in .h)";

if (RelationType=="Association")
	return Implementation + " " + Name;

if (RelationType=="Agregation")
	return Implementation + " " + Name;

if (RelationType=="Composition")
	return Implementation + " " + Name;

if (RelationType=="Generalization")
	return "is a " + PartnerName;

return "to: " + PartnerName;
