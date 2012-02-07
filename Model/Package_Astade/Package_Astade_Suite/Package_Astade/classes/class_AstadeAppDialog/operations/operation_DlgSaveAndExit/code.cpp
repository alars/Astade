//~~ void DlgSaveAndExit(wxCommandEvent& event) [AstadeAppDialog] ~~

wxConfigBase* theConfig = wxConfigBase::Get();

// delete all userapps from config
theConfig->DeleteGroup(wxS("UserApps"));

wxString appStr;
for (unsigned int i = 0; i < lstApps->GetCount(); ++i)
{
	userapp_t* userapp = (userapp_t*)lstApps->GetClientData(i);

	appStr = userapp->filetype;
	theConfig->Write(wxS("/UserApps/") + appStr + wxS("/filetype"), userapp->filetype);
	theConfig->Write(wxS("/UserApps/") + appStr + wxS("/application"), userapp->application);
	theConfig->Write(wxS("/UserApps/") + appStr + wxS("/icon"), userapp->icon);
}

theConfig->Flush();

Show(false);
