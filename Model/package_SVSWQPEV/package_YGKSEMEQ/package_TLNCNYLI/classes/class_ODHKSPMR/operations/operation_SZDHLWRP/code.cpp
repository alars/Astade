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
				myRunTargetList->Append(targets);
								
				wxConfigBase* theConfig = wxConfigBase::Get();
				wxString activeComponent = theConfig->Read("TreeView/ActiveGUID", wxEmptyString);
				sel = theConfig->Read(activeComponent+"/"+myConfigList->GetStringSelection()+"/buildtarget", (long)0);
				myBuildTargetList->SetSelection(sel);
				sel = theConfig->Read(activeComponent+"/"+myConfigList->GetStringSelection()+"/runtarget", (long)0);
				myRunTargetList->SetSelection(sel);
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

SaveCurrentChoice();