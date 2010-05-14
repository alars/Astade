wxFileName classFolder = parentFolder;
parentFolder.AppendDir(wxS("relations"));
if (!wxFileName::DirExists(parentFolder.GetPath()))
	AdeDirectoryElement::CreateNewElement(classFolder, wxS("relations"), ITEM_IS_RELATIONS, false);

wxFileName theRelation = AdeFileElement::CreateNewElement(parentFolder, wxS("relation"), ITEM_IS_RELATION, true);

destination.AppendDir(wxS("relations"));
destination.SetFullName(wxS("ModelNode.ini"));

wxFileConfig theConfig(wxEmptyString,wxEmptyString,theRelation.GetFullPath());

destination.MakeRelativeTo(GetModelPath().GetPath());
destination.SetFullName(wxS("inrelation_") + GUID() + wxS(".ini"));

theConfig.Write(wxS("Astade/PartnerPath"), destination.GetFullPath(wxPATH_UNIX));
theConfig.Write(wxS("Astade/RelationType"), wxS("ImplementationDependency"));

theConfig.Flush();

AdeRelation dummy(theRelation);

return theRelation;
