//wxConfigBase::Set(new wxFileConfig("Astade.ini"));

myFrame = CreateFrame();
myFrame->Init(IsDebugMode());
SetTopWindow(myFrame);
myFrame->Show(TRUE);

return true;