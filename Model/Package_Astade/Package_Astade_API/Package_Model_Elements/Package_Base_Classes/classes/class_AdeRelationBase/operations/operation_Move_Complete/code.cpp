// Call the Move_Complete() hirarchy
AdeFileElement::Move_Complete(parentPath);

wxFileConfig theConfig(wxEmptyString, wxEmptyString, wxEmptyString, myFileName.GetFullPath());

wxString partnerPath;

// Check wether the Partner has a new location or not
if (theConfig.Exists(wxS("Astade/NewPartnerPath")))
	partnerPath = theConfig.Read(wxS("Astade/NewPartnerPath"));
else
	partnerPath = theConfig.Read(wxS("Astade/PartnerPath"));

wxFileName partnerFileName(partnerPath);
partnerFileName.MakeAbsolute();

if (partnerFileName.FileExists())
{
	wxFileConfig partnerConfig(wxEmptyString, wxEmptyString, partnerFileName.GetFullPath());
	wxFileName toFileName(myFileName);
	toFileName.MakeRelativeTo(GetModelPath().GetPath());
	/*
	 * Change the Partners ConfigFile to only use our new location.
	 */
	partnerConfig.Write(wxS("Astade/PartnerPath"), toFileName.GetFullPath(wxPATH_UNIX));
	partnerConfig.DeleteEntry(wxS("Astade/NewPartnerPath"));
}
