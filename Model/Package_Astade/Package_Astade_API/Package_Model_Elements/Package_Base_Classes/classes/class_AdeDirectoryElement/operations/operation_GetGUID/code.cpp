wxFileConfig theConfig(wxEmptyString, wxEmptyString, myFileName.GetFullPath());
wxString aGUID;
aGUID = theConfig.Read(wxS("Astade/GUID"), wxEmptyString);

if (aGUID.empty())
{
	aGUID = GUID();
	theConfig.Write(wxS("Astade/GUID"), aGUID);
}

return aGUID;
