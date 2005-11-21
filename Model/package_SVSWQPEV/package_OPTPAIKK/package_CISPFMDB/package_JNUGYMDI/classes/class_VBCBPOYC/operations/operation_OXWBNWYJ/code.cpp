wxFileConfig theConfig(wxEmptyString,wxEmptyString,myFileName.GetFullPath());

wxString label = theConfig.Read("Astade/Name","<name unknown>");

if (!theConfig.Read("Astade/EntryAction").empty())
{
	label += " Entry: ";
	label += theConfig.Read("Astade/EntryAction");
}

if (!theConfig.Read("Astade/ExitAction").empty())
{
	label += " Exit: ";
	label += theConfig.Read("Astade/ExitAction");
}

return label;