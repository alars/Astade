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

	default:
		command = make.GetFullPath() + " -C \"" +
				component.GetPath() +
				"\" TARGET=" +
				myTree->GetItem(parentID)->GetLabel();
}

myMakeOutput.SetNormalStyle();
myMakeOutput.TheEdit()->Clear();
*myMakeOutput.TheEdit() << "make started ... \n";
myMakeOutput.SetactiveConfiguration(component);

myMakeOutput.Show();
theMakeProcess = new AstadeMakeProcess;

wxExecute(command,wxEXEC_ASYNC,theMakeProcess);
theMakeProcess->theMakeInputStream = theMakeProcess->GetInputStream();
theMakeProcess->theMakeErrorStream = theMakeProcess->GetErrorStream();
