wxFileConfig theConfig(wxEmptyString,wxEmptyString,wxEmptyString,myFileName.GetFullPath());

wxString RelationType = theConfig.Read("Astade/RelationType");

if (RelationType=="ImplementationDependency")
	return 43;

if (RelationType=="SpecificationDependency")
	return 44;

if (RelationType=="Association")
	return 29;

if (RelationType=="Agregation")
	return 31;

if (RelationType=="Composition")
	return 33;

if (RelationType=="Generalization")
	return 35;

return 1;