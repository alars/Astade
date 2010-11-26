//~~ AdeRelationBase(const wxFileName& theFileName) [AdeRelationBase] ~~

thePartnerFileName = myConfig->Read(wxS("Astade/PartnerPath"));
thePartnerFileName.MakeAbsolute();
