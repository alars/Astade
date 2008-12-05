assert(myConfigList);
assert(myBuildTargetList);
assert(myRunTargetList);
		
int sel = myConfigList->GetSelection();

switch(event.GetId())
{
	case ID_TOOL_CONFIG:							
		myBuildTargetList->Clear();				
		myRunTargetList->Clear();		
		
		if(sel != wxNOT_FOUND)
		{						
			assert(myConfigList->GetClientData(sel));			
			wxFileName aFileName(*static_cast<wxFileName*>(myConfigList->GetClientData(sel)));
			aFileName.SetFullName("Makefile");
			if (aFileName.FileExists())
			{				
				AstadeMake aAstadeMake(new AdeMake(aFileName));
				wxArrayString targets(aAstadeMake.GetMakeTargets());
				myBuildTargetList->Append(targets);
				myBuildTargetList->SetSelection(0);
				myRunTargetList->Append(targets);
				myRunTargetList->SetSelection(0);
			}
		}
	break;
	
	case ID_TOOL_BUILDTARGET:
	break;
	
	case ID_TOOL_RUNTARGET:
	break;

	default:
	break;
}