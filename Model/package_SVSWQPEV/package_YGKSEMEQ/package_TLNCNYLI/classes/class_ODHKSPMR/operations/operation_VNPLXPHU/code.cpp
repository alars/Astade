/* vi: set tabstop=4: */

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName coder(theConfig->Read("Tools/Coder"));

wxTreeItemId aID = myTree->GetSelection();

wxFileName componentName(theConfig->Read("TreeView/ActiveComponent"));

AdeComponent theComponent(componentName);

int count = 0;

AdeElementIterator it;
for (it = theComponent.GetFirstBelongingClass(); it != theComponent.end(); ++it)
	count++;

if (count > 0)
{
	wxBusyCursor wait;
	wxProgressDialog progressDialog("Regenerate", "Starting ...", count, this);
	count = 0;

	componentName.AppendDir("auto");

	for (it = theComponent.GetFirstBelongingClass(); it != theComponent.end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();

		progressDialog.Update(count++, anElement->GetLabel());

		componentName.SetName(anElement->GetLabel());
		componentName.SetExt("cpp");

		wxFileName aFile = anElement->GetFileName();
		aFile.MakeAbsolute();

		wxString callName = "\"" + coder.GetFullPath() + "\" " +
			"\"" + aFile.GetFullPath() + "\" " +
			"\"" + componentName.GetFullPath() + "\"";

		AstadeChildProcess* aAstadeChildProcess = new AstadeChildProcess(this);
		aAstadeChildProcess->Redirect();
		wxExecute(callName, wxEXEC_SYNC, aAstadeChildProcess);
		delete aAstadeChildProcess;

		delete anElement;
	}

	myTree->UpdateAll(myTree->GetRootItem());
}
