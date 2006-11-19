wxConfigBase::Set(new wxFileConfig("ACDrawer.ini"));
myFrame = new  ACDrawerFrame;
myFrame->Init();
SetTopWindow(myFrame);
myFrame->Show(true);
return true;