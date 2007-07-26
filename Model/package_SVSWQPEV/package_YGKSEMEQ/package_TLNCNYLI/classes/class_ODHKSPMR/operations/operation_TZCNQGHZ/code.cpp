wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName make(theConfig->Read("Tools/Make"));

wxTreeItemId aID = myTree->GetSelection();

AdeModelElement* element = myTree->GetItem(aID); //Checking the configuration node is selected.

int type = element->GetType(); //Get the item type
if ((type & ITEM_TYPE_MASK) != ITEM_IS_CONFIGURATION )
{
	wxMessageBox("Select the configuration that you want to compile first.");
	return;
}

wxTreeItemId parentID = myTree->GetItemParent(aID);

wxFileName component(myTree->GetItem(aID)->GetFileName());
component.MakeAbsolute();

wxString command;

switch (event.GetId())
{
	case ID_MAKECLEAN:
		command = make.GetFullPath() + " -C \"" +
				component.GetPath() +
				"\" TARGET=" +
				myTree->GetItem(parentID)->GetLabel() +
				" clean";
		break;

	case ID_MAKEALL:
		command = make.GetFullPath() + " -C \"" +
				component.GetPath() +
				"\" TARGET=" +
				myTree->GetItem(parentID)->GetLabel() +
				" clean all";
		break;

	case ID_INSTALL:
		command = make.GetFullPath() + " -C \"" +
				component.GetPath() +
				"\" TARGET=" +
				myTree->GetItem(parentID)->GetLabel() +
				" install";
		break;

	default:
		command = make.GetFullPath() + " -C \"" +
				component.GetPath() +
				"\" TARGET=" +
				myTree->GetItem(parentID)->GetLabel();
}

myMakeOutput->SetNormalStyle();
myMakeOutput->TheEdit()->Clear();
*(myMakeOutput->TheEdit()) << "make started ... \n";
myMakeOutput->SetactiveConfiguration(component);

myMakeOutput->Show();
myMakeOutput->Maximize(false); //true, maximizes the window, otherwise it restores it.
myMakeOutput->Raise();

theMakeProcess = new AstadeMakeProcess;

wxExecute(command,wxEXEC_ASYNC,theMakeProcess);
theMakeProcess->theMakeInputStream = theMakeProcess->GetInputStream();
theMakeProcess->theMakeErrorStream = theMakeProcess->GetErrorStream();
