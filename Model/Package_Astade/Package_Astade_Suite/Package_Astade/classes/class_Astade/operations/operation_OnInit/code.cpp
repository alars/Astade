//~~ bool OnInit() [Astade] ~~

wxConfigBase::Set(new wxFileConfig(wxS("Astade.ini")));

::wxInitAllImageHandlers();
InitializeFrame();

return true;
