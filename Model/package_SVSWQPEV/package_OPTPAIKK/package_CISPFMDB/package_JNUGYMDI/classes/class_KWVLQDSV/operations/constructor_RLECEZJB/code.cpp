if (!GetHasChildren())
{
	AdeDirectoryElement::CreateNewElement(myFileName,"auto",ITEM_IS_FILES,false);
	AdeDirectoryElement::CreateNewElement(myFileName,"manual",ITEM_IS_FILES,false);
}

//Just make sure, that the filename of the aktive component is in Astade.ini
//It might have changed, becaus someone renamed it;
wxConfigBase* theConfig = wxConfigBase::Get();
wxString activeGUID = theConfig->Read("TreeView/ActiveGUID");
if (activeGUID == GetGUID())
{
	theConfig->Write("TreeView/ActiveComponent",GetFileName().GetFullPath());
	theConfig->Flush();
}