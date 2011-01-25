//~~ AdeComponent(const wxFileName& theFileName) [AdeComponent] ~~

wxFileName aFileName = myFileName;
aFileName.SetFullName(wxEmptyString);
aFileName.AppendDir(wxS("auto"));
if (!aFileName.DirExists())
	AdeDirectoryElement::CreateNewElement(myFileName, wxS("auto"), ITEM_IS_FILES, false);

aFileName = myFileName;
aFileName.SetFullName(wxEmptyString);
aFileName.AppendDir(wxS("manual"));
if (!aFileName.DirExists())
	AdeDirectoryElement::CreateNewElement(myFileName, wxS("manual"), ITEM_IS_FILES, false);

aFileName = myFileName;
aFileName.SetFullName(wxEmptyString);
aFileName.AppendDir(wxS("diagrams"));
if (!aFileName.DirExists())
	AdeDirectoryElement::CreateNewElement(myFileName, wxS("diagrams"), ITEM_IS_FILES, false);

//Just make sure that the filename of the active component is in Astade.ini
//It might have changed, because someone renamed it;
wxConfigBase* theConfig = wxConfigBase::Get();
wxString activeGUID = theConfig->Read(wxS("TreeView/ActiveGUID"));
if (activeGUID == GetGUID())
{
	theConfig->Write(wxS("TreeView/ActiveComponent"), GetFileName().GetFullPath());
	theConfig->Flush();
}
