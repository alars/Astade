assert(myConfigList);
assert(myBuildTargetList);
assert(myRunTargetList);

switch(event.GetId())
{
	case ID_TOOL_GENERATE:
		DoGenerate(false);
	break;
	
	case ID_TOOL_BUILD:
	{
		/* get configuration to build */
		int n = myConfigList->GetSelection();
		wxFileName* configFile = static_cast<wxFileName*>(myConfigList->GetClientData(n));
		assert(configFile);
		AdeConfiguration* aConfiguration = dynamic_cast<AdeConfiguration*>(AdeModelElement::CreateNewElement(*configFile));
		assert(aConfiguration);
	
		/* get make target to build */		
		wxString target = myBuildTargetList->GetStringSelection();
		
		/* run make */
		RunMake(*aConfiguration, target);
				
		delete aConfiguration;
	}		
	break;
	
	case ID_TOOL_FASTBUILD:
		DoGenerate(false);
	break;

	case ID_TOOL_RUN:
	{
		/* get configuration to build */
		int n = myConfigList->GetSelection();
		wxFileName* configFile = static_cast<wxFileName*>(myConfigList->GetClientData(n));
		assert(configFile);
		AdeConfiguration* aConfiguration = dynamic_cast<AdeConfiguration*>(AdeModelElement::CreateNewElement(*configFile));
		assert(aConfiguration);
	
		/* get make target to build */		
		wxString target = myRunTargetList->GetStringSelection();
		
		/* run make */
		RunMake(*aConfiguration, target);
				
		delete aConfiguration;
	}		
	break;
	
	case ID_TOOL_FASTRUN:
		DoGenerate(false);
	break;
	
	default:
	break;
}
