wxConfigBase::Set(new wxFileConfig("ACDrawer.ini"));
myPanel = new  ACPanel;
myPanel->Load(*wxConfigBase::Get());