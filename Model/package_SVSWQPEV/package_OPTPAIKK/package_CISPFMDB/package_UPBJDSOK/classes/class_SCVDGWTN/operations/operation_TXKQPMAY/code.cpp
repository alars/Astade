// Call the Move_Complete() hirarchy
AdeFileElement::Move_Complete(parentPath);

wxFileConfig theConfig(wxEmptyString, wxEmptyString, wxEmptyString, myFileName.GetFullPath());

wxString partnerPath;

// Check wether the Partner has a new location or not
if(theConfig.Exists("Astade/NewPartnerPath"))
{
	partnerPath = theConfig.Read("Astade/NewPartnerPath");
}
else
{
	partnerPath = theConfig.Read("Astade/PartnerPath");
}

wxFileName partnerFileName(partnerPath);
partnerFileName.MakeAbsolute();

if(partnerFileName.FileExists())
{
	wxConfigBase* aConfig = wxConfigBase::Get();
	wxString modelPath = aConfig->Read("TreeView/ModelPath");

	wxFileConfig partnerConfig(wxEmptyString, wxEmptyString, partnerFileName.GetFullPath());
	wxFileName toFileName(myFileName);
	toFileName.MakeRelativeTo(modelPath);
	/*
	 * Change the Partners ConfigFile to only use our new location.
	 */
	partnerConfig.Write("Astade/PartnerPath", toFileName.GetFullPath(wxPATH_UNIX));
	partnerConfig.DeleteEntry("Astade/NewPartnerPath");
}