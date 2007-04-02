me = this;

wxConfigBase::Set(new wxFileConfig("Astade.ini"));
wxInitAllImageHandlers();

InitializeFrame();
return true;
