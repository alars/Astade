//~~ void CallMake(wxCommandEvent& event) [AstadeFrame] ~~

// TODO: Use RunMake(config, target) instead to remove duplicate code

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName make(theConfig->Read(wxS("Tools/Make")));

wxTreeItemId anID = myTree->GetSelection();

AdeModelElement* element = myTree->GetItem(anID); //Checking the configuration node is selected.

int type = element->GetType(); //Get the item type
if ((type & ITEM_TYPE_MASK) != ITEM_IS_CONFIGURATION)
{
	wxMessageBox(wxS("Select the configuration that you want to compile first."));
	return;
}

wxTreeItemId parentID = myTree->GetItemParent(anID);

wxFileName component(myTree->GetItem(anID)->GetFileName());
component.MakeAbsolute();

wxString command;

if (event.GetId() >= ID_MAKEMIN && event.GetId() <= ID_MAKEMAX)
{
	int runIdx = event.GetId() - ID_MAKEMIN;

	wxFileName aFileName(component);
	aFileName.SetFullName(wxS("Makefile"));
	if (aFileName.FileExists())
	{
		AstadeMake myAstadeMake(new AdeMake(aFileName));
		wxArrayString targets(myAstadeMake.GetMakeTargets());
		if (targets.GetCount() > static_cast<size_t>(runIdx))
		{
			command = make.GetFullPath() + wxS(" -C \"") +
					component.GetPath() +
					wxS("\" ") +
					wxS("\"TRACECLASSES=") + GetTraceClassList() + wxS("\" \"TARGET=") +
					myTree->GetItem(parentID)->GetLabel() +
					wxS("\" ") + targets[runIdx];
		}
		else
		{
			wxASSERT_MSG(0, wxS("The target does not exist in the Makefile."));
		}
	}
	else
	{
		wxASSERT_MSG(0, wxS("The configuration has no Makefile!"));
	}
}
else
	return;

myMakeOutput->SetNormalStyle();
myMakeOutput->TheEdit()->Clear();
*(myMakeOutput->TheEdit()) << wxS("make started ...\n");
myMakeOutput->SetactiveConfiguration(component);

myMakeOutput->Show();
myMakeOutput->Maximize(false); //true, maximizes the window, otherwise it restores it.
myMakeOutput->Raise();

theMakeProcess = new AstadeMakeProcess(*this);

runningMakePid = wxExecute(command,wxEXEC_ASYNC | wxEXEC_MAKE_GROUP_LEADER,theMakeProcess);
theMakeProcess->theMakeInputStream = theMakeProcess->GetInputStream();
theMakeProcess->theMakeErrorStream = theMakeProcess->GetErrorStream();
