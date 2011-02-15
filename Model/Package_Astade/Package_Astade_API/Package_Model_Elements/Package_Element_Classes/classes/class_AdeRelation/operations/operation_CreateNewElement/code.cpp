//~~ wxFileName CreateNewElement(wxFileName parentFolder, wxFileName destination) [AdeRelation] ~~

wxFileName classFolder = parentFolder;
parentFolder.AppendDir(wxS("relations"));
if (!wxFileName::DirExists(parentFolder.GetPath()))
	AdeDirectoryElement::CreateNewElement(classFolder, wxS("relations"), ITEM_IS_RELATIONS, false);

destination.SetFullName(wxS("ModelNode.ini"));
AdeModelElement* theClass = AdeModelElement::CreateNewElement(destination);
wxString estimatedFilename(wxS("relation_") + theClass->GetName());
delete theClass;

estimatedFilename.Replace(wxS(" "), wxS("_"));

wxString forbidden(wxFileName::GetForbiddenChars(wxPATH_UNIX));
forbidden += wxFileName::GetForbiddenChars(wxPATH_WIN);
forbidden += wxFileName::GetForbiddenChars(wxPATH_MAC);

for (unsigned int i = 0; i < forbidden.size(); i++)
	estimatedFilename.Replace(wxString(forbidden[i]), wxS("_"));

wxFileName theFilename(parentFolder);
theFilename.SetName(estimatedFilename);
theFilename.SetExt(wxS("ini"));
for (int count = 1; theFilename.FileExists(); ++count)
{
	wxString suffix;
	suffix << count;
	theFilename.SetName(estimatedFilename + wxS("_") + suffix);
}

wxFileName theRelation = AdeFileElement::CreateNewElement(parentFolder, theFilename.GetName(), ITEM_IS_RELATION, false);

destination.AppendDir(wxS("relations"));

classFolder.SetFullName(wxS("ModelNode.ini"));
AdeModelElement* myClass = AdeModelElement::CreateNewElement(classFolder);
estimatedFilename = wxS("inrelation_") + myClass->GetName();
delete myClass;

theFilename = destination;
theFilename.SetName(estimatedFilename);
theFilename.SetExt(wxS("ini"));
for (int count = 1; theFilename.FileExists(); ++count)
{
	wxString suffix;
	suffix << count;
	theFilename.SetName(estimatedFilename + wxS("_") + suffix);
}

wxFileConfig theConfig(wxEmptyString, wxEmptyString, theRelation.GetFullPath());

destination.MakeRelativeTo(GetModelPath().GetPath());
destination.SetFullName(theFilename.GetFullName());

theConfig.Write(wxS("Astade/PartnerPath"), destination.GetFullPath(wxPATH_UNIX));
theConfig.Write(wxS("Astade/RelationType"), wxS("ImplementationDependency"));

theConfig.Flush();

AdeRelation dummy(theRelation);

return theRelation;
