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

myConfigList->SetSelection(0);