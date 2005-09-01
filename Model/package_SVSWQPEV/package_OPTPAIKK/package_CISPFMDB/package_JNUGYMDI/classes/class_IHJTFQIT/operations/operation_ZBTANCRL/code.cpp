wxFileConfig thePartnerConfig(wxEmptyString,wxEmptyString,wxEmptyString,GetPartnerFile().GetFullPath());

wxString RelationType = thePartnerConfig.Read("Astade/RelationType");

if (RelationType=="ImplementationDependency")
	return 28;

if (RelationType=="SpecificationDependency")
	return 28;

if (RelationType=="Association")
	return 30;

if (RelationType=="Agregation")
	return 32;

if (RelationType=="Composition")
	return 34;

if (RelationType=="Generalization")
	return 36;

return 1;