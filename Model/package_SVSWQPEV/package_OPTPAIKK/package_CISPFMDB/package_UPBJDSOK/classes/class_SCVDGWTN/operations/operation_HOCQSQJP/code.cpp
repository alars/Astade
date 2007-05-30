if(PartnerExists())
{
	wxConfigBase* aConfig = wxConfigBase::Get();
	wxString modelPath = aConfig->Read("TreeView/ModelPath");

	wxFileName toFileName(parentPath.GetPath(), myFileName.GetFullName());
	toFileName.MakeRelativeTo(modelPath);

	wxFileName partnerFileName = GetPartnerFile();


	/*
	 * Save the new location in the Partners ConfigFile, so that
	 * the Partner can find us in both places
 	 */
	wxFileConfig partnerConfig(wxEmptyString, wxEmptyString, partnerFileName.GetFullPath());
	partnerConfig.Write("Astade/NewPartnerPath", toFileName.GetFullPath(wxPATH_UNIX));
}