assert(myConfigList);
assert(myBuildTargetList);
assert(myRunTargetList);

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName componentName(theConfig->Read("TreeView/ActiveComponent"));
AdeComponent activeComponent(componentName);

for(unsigned int i=0; i<myConfigList->GetCount(); i++)
	delete static_cast<wxFileName*>(myConfigList->GetClientData(i));
			
myConfigList->Clear();
		
AdeElementIterator iter = activeComponent.begin();
while(iter != activeComponent.end())
{
	AdeModelElement* anElement = iter.CreateNewElement();
	AdeConfiguration* aConfiguration = dynamic_cast<AdeConfiguration*>(anElement);
	if(aConfiguration)
		myConfigList->Append(aConfiguration->GetLabel(), new wxFileName(aConfiguration->GetFileName()));
	
	delete anElement;
	
	++iter;
}

int sel = 0;
sel = theConfig->Read(activeComponent.GetGUID()+"/configuration", (long)0);
myConfigList->SetSelection(sel);
myConfigList->SetSize(myConfigList->GetBestSize());

wxCommandEvent event(wxEVT_COMMAND_CHOICE_SELECTED, ID_TOOL_CONFIG);
OnChoice(event);
/*
sel = theConfig->Read(activeComponent.GetGUID()+"/"+myConfigList->GetStringSelection()+"/buildtarget", (long)0);
myBuildTargetList->SetSelection(sel);
sel = theConfig->Read(activeComponent.GetGUID()+"/"+myConfigList->GetStringSelection()+"/runtarget", (long)0);
myRunTargetList->SetSelection(sel);
*/
