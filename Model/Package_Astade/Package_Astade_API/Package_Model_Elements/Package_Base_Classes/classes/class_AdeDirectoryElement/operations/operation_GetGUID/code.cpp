//~~ wxString GetGUID() [AdeDirectoryElement] ~~

wxString aGUID;
aGUID = myConfig->Read(wxS("Astade/GUID"), wxEmptyString);

if (aGUID.empty())
{
	aGUID = GUID();
	myConfig->Write(wxS("Astade/GUID"), aGUID);
	myConfig->Flush();
}

return aGUID;
