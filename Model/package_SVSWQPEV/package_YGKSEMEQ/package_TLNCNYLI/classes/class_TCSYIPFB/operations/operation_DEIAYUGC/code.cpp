wxConfigBase* theConfig = wxConfigBase::Get();

// delete all userapps from config
theConfig->DeleteGroup("UserApps");

wxListItem aItem;

wxString appStr;
for(int i=0; i<lstApps->GetItemCount(); i++)
{
	//appStr.Printf("App_%d", i);
	
	aItem.SetId(i);
	aItem.SetColumn(0);
	lstApps->GetItem(aItem);
	appStr = aItem.GetText();
	theConfig->Write("/UserApps/"+appStr+"/filetype", aItem.GetText());
	aItem.SetColumn(1);
	lstApps->GetItem(aItem);
	theConfig->Write("/UserApps/"+appStr+"/application", aItem.GetText());
	aItem.SetColumn(2);
	lstApps->GetItem(aItem);
	theConfig->Write("/UserApps/"+appStr+"/icon", aItem.GetText());
}

theConfig->Flush();

Show(false);
