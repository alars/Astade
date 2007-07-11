wxConfigBase* theConfig = wxConfigBase::Get();

// delete all userapps from config
theConfig->DeleteGroup("UserApps");

wxString appStr;
for (unsigned int i = 0; i < lstApps->GetCount(); i++)
{
	//appStr.Printf("App_%d", i);

	userapp_t* userapp = (userapp_t*)lstApps->GetClientData(i);

	appStr = userapp->filetype;
	theConfig->Write("/UserApps/"+appStr+"/filetype", userapp->filetype);
	theConfig->Write("/UserApps/"+appStr+"/application", userapp->application);
	theConfig->Write("/UserApps/"+appStr+"/icon", userapp->icon);
}

theConfig->Flush();

Show(false);
