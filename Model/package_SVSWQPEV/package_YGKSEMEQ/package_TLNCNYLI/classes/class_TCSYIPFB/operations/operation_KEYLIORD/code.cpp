wxConfigBase* theConfig = wxConfigBase::Get();

lstApps->DeleteAllItems();
theConfig->SetPath("/UserApps");

wxString groupName;
long groupIndex;

for(bool i=theConfig->GetFirstGroup(groupName, groupIndex); i==true; 
			i=theConfig->GetNextGroup(groupName, groupIndex))
{
	lstApps->InsertItem(0, theConfig->Read(groupName+"/filetype"));
	lstApps->SetItem(0, 1, theConfig->Read(groupName+"/application"));
	lstApps->SetItem(0, 2, theConfig->Read(groupName+"/icon"));
}

theConfig->SetPath("/");

btnCancel->SetFocus();

Show(true);
