//~~ void DlgShow() [AstadeAppDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();

lstApps->Clear();
theConfig->SetPath(wxS("/UserApps"));

wxString groupName;
long groupIndex;

for (bool i = theConfig->GetFirstGroup(groupName, groupIndex); i;
			i = theConfig->GetNextGroup(groupName, groupIndex))
{
/*	lstApps->InsertItem(0, theConfig->Read(groupName+"/filetype"));
	lstApps->SetItem(0, 1, theConfig->Read(groupName+"/application"));
	lstApps->SetItem(0, 2, theConfig->Read(groupName+"/icon"));*/
	int retVal = lstApps->Append(theConfig->Read(groupName + wxS("/application")));
	if (retVal >= 0)
	{
		userapp_t* userapp = new userapp_t();
		userapp->filetype =	theConfig->Read(groupName + wxS("/filetype"));
		userapp->application = theConfig->Read(groupName + wxS("/application"));
		userapp->icon = theConfig->Read(groupName + wxS("/icon"));
		lstApps->SetClientData(retVal, userapp);
	}
}

theConfig->SetPath(wxS("/"));

btnCancel->SetFocus();
txtExt->Clear();
txtApp->Clear();
txtIcon->Clear();

Show(true);
