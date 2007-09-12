/* vi: set tabstop=4: */

wxString PartnerName(GetPartnerName());

if (myConfig->Read("Astade/PartnerClassname", wxEmptyString) != PartnerName)
{
	myConfig->Write("Astade/PartnerClassname", PartnerName);
	if (myConfig->Read("Astade/Name", wxEmptyString) == "relation")
		myConfig->Write("Astade/Name", wxString("my") + PartnerName);
}

wxString RelationType(myConfig->Read("Astade/RelationType"));
wxString Implementation(myConfig->Read("Astade/Implementation"));
wxString Name(myConfig->Read("Astade/Name"));
wxString Default(myConfig->Read("Astade/Default"));
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