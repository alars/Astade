wxConfigBase::Set(new wxFileConfig("ACDrawer.ini"));
wxConfigBase::Get()->Write("Nodes/Node_1/Label","Test_1");
wxConfigBase::Get()->Write("Nodes/Node_2/Label","Test_2");
myFrame = new  ACDrawerFrame;
SetTopWindow(myFrame);
myFrame->Show(true);
return true;