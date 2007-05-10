wxConfigBase* theConfig = wxConfigBase::Get();

lstApps->Clear();
theConfig->SetPath("/UserApps");

wxString groupName;
long groupIndex;

for(bool i=theConfig->GetFirstGroup(groupName, groupIndex); i==true;
			i=theConfig->GetNextGroup(groupName, groupIndex))
{
/*	lstApps->InsertItem(0, theConfig->Read(groupName+"/filetype"));
	lstApps->SetItem(0, 1, theConfig->Read(groupName+"/application"));
	lstApps->SetItem(0, 2, theConfig->Read(groupName+"/icon"));*/
	int retVal = lstApps->Append(theConfig->Read(groupName+"/application"));
	if(retVal>=0)
	{
		userapp_t* userapp = new userapp_t();
		userapp->filetype =	theConfig->Read(groupName+"/filetype");
		userapp->application = theConfig->Read(groupName+"/application");
		userapp->icon = theConfig->Read(groupName+"/icon");
		lstApps->SetClientData(retVal, userapp);
	}
}

theConfig->SetPath("/");

btnCancel->SetFocus();
txtExt->Clear();
txtApp->Clear();
txtIcon->Clear();


Show(true);
