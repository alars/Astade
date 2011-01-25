//~~ AdeComponent(const wxFileName& theFileName) [AdeComponent] ~~
if (!HasChildren())
{
	AdeDirectoryElement::CreateNewElement(myFileName, wxS("auto"), ITEM_IS_FILES, false);
	AdeDirectoryElement::CreateNewElement(myFileName, wxS("manual"), ITEM_IS_FILES, false);
}

//Just make sure that the filename of the active component is in Astade.ini
//It might have changed, because someone renamed it;
wxConfigBase* theConfig = wxConfigBase::Get();
wxString activeGUID = theConfig->Read(wxS("TreeView/ActiveGUID"));
if (activeGUID == GetGUID())
{
	theConfig->Write(wxS("TreeView/ActiveComponent"), GetFileName().GetFullPath());
	theConfig->Flush();
}
