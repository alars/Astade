wxString PartnerPath = myConfig->Read(wxS("Astade/PartnerPath"));
wxFileName PartnerFile(PartnerPath);
PartnerFile.MakeAbsolute();
thePartnerFileName = PartnerFile;
