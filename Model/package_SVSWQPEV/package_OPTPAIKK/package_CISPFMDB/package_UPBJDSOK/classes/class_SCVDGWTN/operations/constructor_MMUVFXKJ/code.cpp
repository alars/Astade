wxString PartnerPath = myConfig->Read("Astade/PartnerPath");
wxFileName PartnerFile(PartnerPath);
PartnerFile.MakeAbsolute();
thePartnerFileName = PartnerFile;