wxFileName classFolder = parentFolder;
parentFolder.AppendDir("relations");
if (!wxFileName::DirExists(parentFolder.GetPath()))
	AdeDirectoryElement::CreateNewElement(classFolder,"relations",ITEM_IS_RELATIONS,false);

wxFileName theRelation = AdeFileElement::CreateNewElement(parentFolder,"relation",ITEM_IS_RELATION,true);

destination.AppendDir("relations");
destination.SetFullName("ModelNode.ini");

wxFileConfig theConfig(wxEmptyString,wxEmptyString,theRelation.GetFullPath());

wxConfigBase* aConfig = wxConfigBase::Get();
wxString modelPath = aConfig->Read("TreeView/ModelPath");

destination.MakeRelativeTo(modelPath);
destination.SetFullName(wxString("inrelation_")+GUID()+".ini");

theConfig.Write("Astade/PartnerPath", destination.GetFullPath(wxPATH_UNIX));
theConfig.Write("Astade/RelationType", "ImplementationDependency");
