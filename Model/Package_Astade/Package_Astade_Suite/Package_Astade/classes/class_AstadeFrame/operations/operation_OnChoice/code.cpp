//~~ void OnChoice(wxCommandEvent& event) [AstadeFrame] ~~

assert(myConfigList);
assert(myBuildTargetList);
assert(myRunTargetList);

int sel = myConfigList->GetSelection();

switch(event.GetId())
{
	case ID_TOOL_CONFIG:
		myBuildTargetList->Clear();
		myRunTargetList->Clear();

		if (sel != wxNOT_FOUND)
		{
			assert(myConfigList->GetClientData(sel));
			wxFileName aFileName(*static_cast<wxFileName*>(myConfigList->GetClientData(sel)));
			aFileName.SetFullName(wxS("Makefile"));
			if (aFileName.FileExists())
			{
				AstadeMake anAstadeMake(new AdeMake(aFileName));
				wxArrayString targets(anAstadeMake.GetMakeTargets());
				myBuildTargetList->Append(targets);
				myRunTargetList->Append(targets);

				wxConfigBase* theConfig = wxConfigBase::Get();
				wxString activeComponent = theConfig->Read(wxS("TreeView/ActiveGUID"), wxEmptyString);
				sel = theConfig->Read(activeComponent + wxS("/") + myConfigList->GetStringSelection() + wxS("/buildtarget"), 0L);
				myBuildTargetList->SetSelection(sel);
				myBuildTargetList->SetSize(myBuildTargetList->GetBestSize());
				sel = theConfig->Read(activeComponent + wxS("/") + myConfigList->GetStringSelection() + wxS("/runtarget"), 0L);
				myRunTargetList->SetSelection(sel);
				myRunTargetList->SetSize(myRunTargetList->GetBestSize());
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
