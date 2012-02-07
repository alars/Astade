//~~ void SaveCurrentChoice() [AstadeFrame] ~~

assert(myConfigList);
assert(myBuildTargetList);
assert(myRunTargetList);

wxConfigBase* theConfig = wxConfigBase::Get();

wxString activeComponent = theConfig->Read(wxS("TreeView/ActiveGUID"), wxEmptyString);

if(!activeComponent.IsEmpty())
{
	theConfig->Write(activeComponent + wxS("/configuration"), myConfigList->GetSelection());
	theConfig->Write(activeComponent + wxS("/") + myConfigList->GetStringSelection() + wxS("/buildtarget"), myBuildTargetList->GetSelection());
	theConfig->Write(activeComponent + wxS("/") + myConfigList->GetStringSelection() + wxS("/runtarget"), myRunTargetList->GetSelection());
}
