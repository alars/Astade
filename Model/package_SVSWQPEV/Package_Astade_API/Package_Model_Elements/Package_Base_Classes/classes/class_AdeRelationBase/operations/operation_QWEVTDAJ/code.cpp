wxFileName toFileName = AdeModelElement::Move(parentPath);

wxFileName partnerFileName = GetPartnerFile();
wxFileConfig partnerConfig(wxEmptyString, wxEmptyString, partnerFileName.GetFullPath());
partnerConfig.Write("Astade/PartnerPath", toFileName.GetFullPath(wxPATH_UNIX));

return toFileName;