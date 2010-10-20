//~~ void Move_Complete(wxFileName parentPath) [AdeRelationBase] ~~

// Call the Move_Complete() hierarchy
AdeFileElement::Move_Complete(parentPath);

wxString partnerPath;

// Check wether the Partner has a new location or not
if (myConfig->Exists(wxS("Astade/NewPartnerPath")))
	partnerPath = myConfig->Read(wxS("Astade/NewPartnerPath"));
else
	partnerPath = myConfig->Read(wxS("Astade/PartnerPath"));

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
