//~~ void UpdateToolbar() [AstadeFrame] ~~

assert(myConfigList);
assert(myBuildTargetList);
assert(myRunTargetList);

for (unsigned int i = 0; i < myConfigList->GetCount(); i++)
	delete static_cast<wxFileName*>(myConfigList->GetClientData(i));
myConfigList->Clear();

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName componentName(theConfig->Read(wxS("TreeView/ActiveComponent")));
if (componentName.GetFullPath() != wxS("none"))
{
	AdeComponent activeComponent(componentName);

	for (AdeElementIterator iter = activeComponent.begin(); iter != activeComponent.end(); ++iter)
	{
		AdeModelElement* anElement = iter.CreateNewElement();
		AdeConfiguration* aConfiguration = dynamic_cast<AdeConfiguration*>(anElement);
		if (aConfiguration)
			myConfigList->Append(aConfiguration->GetLabel(), new wxFileName(aConfiguration->GetFileName()));

		delete anElement;
	}

	int sel = 0;
	sel = theConfig->Read(activeComponent.GetGUID() + wxS("/configuration"), 0L);
	myConfigList->SetSelection(sel);
}
myConfigList->SetSize(myConfigList->GetBestSize());

wxCommandEvent event(wxEVT_COMMAND_CHOICE_SELECTED, ID_TOOL_CONFIG);
OnChoice(event);
