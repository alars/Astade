assert(myConfigList);
assert(myBuildTargetList);
assert(myRunTargetList);

/*
int sel = myConfigList->GetSelection();

if(sel != wxNOT_FOUND)
{						
	assert(myConfigList->GetClientData(sel));			
	wxFileName aFileName(*static_cast<wxFileName*>(myConfigList->GetClientData(sel)));
	AdeConfiguration* configuration = dynamic_cast<AdeConfiguration*>(AdeModelElement::CreateNewElement(aFileName));
	assert(configuration);
	configuration->GetGUID();
}
*/