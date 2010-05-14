if (PartnerExists())
{
	wxFileName partnerFileName(GetPartnerFile());

	wxFileConfig partnerConfig(wxEmptyString, wxEmptyString, partnerFileName.GetFullPath());
	partnerConfig.DeleteEntry(wxS("Astade/NewPartnerPath"));
}
