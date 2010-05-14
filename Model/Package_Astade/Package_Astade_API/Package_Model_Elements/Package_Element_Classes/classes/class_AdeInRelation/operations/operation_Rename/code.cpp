wxFileName newFilename(GuessGoodFilename(wxS("inrelation_") + GetPartnerName()));

if (GetFileName() != newFilename)
{
	int rc = AdeRevisionControlBase::GetRevisionControlObject()->Move(GetFileName(), newFilename);
	if (rc == 0)
	{
		SetFileName(newFilename);
		if (PartnerExists())
		{
			wxFileConfig partnerConfig(wxEmptyString, wxEmptyString, GetPartnerFile().GetFullPath());
			newFilename.MakeRelativeTo(GetModelPath().GetPath());
			partnerConfig.Write(wxS("Astade/PartnerPath"), newFilename.GetFullPath(wxPATH_UNIX));
		}
	}
}
