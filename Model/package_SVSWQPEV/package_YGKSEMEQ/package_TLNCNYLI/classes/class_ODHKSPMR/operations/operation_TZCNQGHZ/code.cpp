wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName make(theConfig->Read("Tools/Make"));

wxTreeItemId aID = myTree->GetSelection();
wxTreeItemId parentID = myTree->GetItemParent(aID);

wxFileName component(myTree->GetItem(aID)->GetFileName());
component.MakeAbsolute();

wxString command;

switch (event.GetId())
{
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

	case ID_RUN:
		command = component.GetPath() + "/" +	myTree->GetItem(parentID)->GetLabel();
		break;

	default:
		command = make.GetFullPath() + " -C \"" +
				component.GetPath() +
				"\" TARGET=" +
				myTree->GetItem(parentID)->GetLabel();
}

myMakeOutput.SetNormalStyle();
myMakeOutput.theEdit.Clear();
myMakeOutput.theEdit << "make started ... \n";

myMakeOutput.Show();
theMakeProcess = new AstadeMakeProcess;

wxExecute(command,wxEXEC_ASYNC,theMakeProcess);
theMakeProcess->theMakeInputStream = theMakeProcess->GetInputStream();
theMakeProcess->theMakeErrorStream = theMakeProcess->GetErrorStream();
