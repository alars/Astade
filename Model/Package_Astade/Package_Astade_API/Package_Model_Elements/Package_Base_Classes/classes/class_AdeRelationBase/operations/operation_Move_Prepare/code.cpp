if (PartnerExists())
{
	wxFileName toFileName(parentPath.GetPath(), myFileName.GetFullName());
	toFileName.MakeRelativeTo(GetModelPath().GetPath());

	wxFileName partnerFileName(GetPartnerFile());

	/*
	 * Save the new location in the Partners ConfigFile, so that
	 * the Partner can find us in both places
 	 */
	wxFileConfig partnerConfig(wxEmptyString, wxEmptyString, partnerFileName.GetFullPath());
	partnerConfig.Write(wxS("Astade/NewPartnerPath"), toFileName.GetFullPath(wxPATH_UNIX));
}
