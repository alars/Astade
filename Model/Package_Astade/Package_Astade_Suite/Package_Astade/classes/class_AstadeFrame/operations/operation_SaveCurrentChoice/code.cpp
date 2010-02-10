assert(myConfigList);
assert(myBuildTargetList);
assert(myRunTargetList);

wxConfigBase* theConfig = wxConfigBase::Get();

wxString activeComponent = theConfig->Read("TreeView/ActiveGUID", wxEmptyString);

if(!activeComponent.IsEmpty())
{
	theConfig->Write(activeComponent+"/configuration", myConfigList->GetSelection());
	theConfig->Write(activeComponent+"/"+myConfigList->GetStringSelection()+"/buildtarget", myBuildTargetList->GetSelection());
	theConfig->Write(activeComponent+"/"+myConfigList->GetStringSelection()+"/runtarget", myRunTargetList->GetSelection());
}