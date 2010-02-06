wxFileConfig theConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());
wxString aGUID;

aGUID = theConfig.Read("Astade/GUID",wxEmptyString);

if (aGUID.empty())
{
	aGUID = GUID();
	theConfig.Write("Astade/GUID",aGUID);
}

return aGUID;