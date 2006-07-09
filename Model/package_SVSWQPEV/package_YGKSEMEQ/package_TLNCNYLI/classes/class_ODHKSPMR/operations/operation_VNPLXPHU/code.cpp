/* vi: set tabstop=4: */

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName coder(theConfig->Read("Tools/Coder"));
wxFileName statechartCoder(theConfig->Read("Tools/StatechartCoder"));

wxTreeItemId aID = myTree->GetSelection();

wxFileName componentName(theConfig->Read("TreeView/ActiveComponent"));

AdeComponent theComponent(componentName);
componentName.AppendDir("auto");

wxString filename;
wxArrayString names;
wxDir::GetAllFiles(componentName.GetPath(), &names, wxEmptyString, wxDIR_FILES);

for (unsigned int i=0; i<names.GetCount();i++)
{
	componentName.SetFullName(names[i]);

	if (componentName.GetFullName() != "ModelNode.ini")
		wxRemoveFile(componentName.GetFullPath());
}

AdeElementIterator it;
int count = 0;
for (it = theComponent.GetFirstBelongingClass(); it != theComponent.end(); ++it)
	count++;

for (it = theComponent.GetFirstBelongingStatechart(); it != theComponent.end(); ++it)
	count++;

if (count > 0)
{
	wxBusyCursor wait;
	wxProgressDialog progressDialog("Regenerate", "Starting ...", count, this, wxPD_AUTO_HIDE | wxPD_ELAPSED_TIME | wxPD_ESTIMATED_TIME | wxPD_REMAINING_TIME | wxPD_SMOOTH );
	count = 0;

	// Generating the classes
	for (it = theComponent.GetFirstBelongingClass(); it != theComponent.end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();

		progressDialog.Update(count++, anElement->GetName());

		componentName.SetName(anElement->GetName());
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

	// Generating the statecharts
	for (it = theComponent.GetFirstBelongingStatechart(); it != theComponent.end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();

		progressDialog.Update(count++, anElement->GetName());

		componentName.SetName(anElement->GetName());
		componentName.SetExt("cpp");

		wxFileName aFile = anElement->GetFileName();
		aFile.MakeAbsolute();

		wxString callName = "\"" + statechartCoder.GetFullPath() + "\" " +
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
