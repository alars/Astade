wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,myFileName.GetFullPath());

wxString RelationType = theConfig.Read("Astade/RelationType");

if (RelationType=="ImplementationDependency")
	return 26;

if (RelationType=="SpecificationDependency")
	return 26;

if (RelationType=="Association")
	return 29;

if (RelationType=="Agregation")
	return 31;

if (RelationType=="Composition")
	return 33;

if (RelationType=="Generalization")
	return 35;

return 1;