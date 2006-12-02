wxConfigBase::Set(new wxFileConfig("ACDrawer.ini"));
myPanel = new  ACPanel;
//myPanel->Load(*wxConfigBase::Get());
myPanel->New();
wxConfigBase::Get()->DeleteAll();
wxConfigBase::Set(new wxFileConfig("ACDrawer.ini"));
myPanel->Save(*wxConfigBase::Get());
wxConfigBase::Get()->Flush();