wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName coder(theConfig->Read("Tools/Coder"));

wxTreeItemId aID = myTree->GetSelection();

wxFileName componentName(theConfig->Read("TreeView/ActiveComponent"));

AdeComponent theComponent(componentName);

int count=0;

for (AdeElementIterator it = theComponent.GetFirstBelongingClass();
	 it!=theComponent.end();
	 ++it)
{
	count++;
}

if (count)
{

	wxBusyCursor wait;

	wxProgressDialog progressDialog("Regenerate", "Starting ...", count, this);
	int done = 0;

	componentName.AppendDir("auto");

	for (AdeElementIterator it = theComponent.GetFirstBelongingClass();
		 it!=theComponent.end();
		 ++it)
	{
		AdeModelElement* aElement = it.CreateNewElement();

		progressDialog.Update( done, aElement->GetLabel());

		componentName.SetName(aElement->GetLabel());
		componentName.SetExt("cpp");

		++done;

		wxFileName aFile = aElement->GetFileName();
		aFile.MakeAbsolute();

		wxString callName = "\"" + coder.GetFullPath() + "\" " +
			"\"" + aFile.GetFullPath() + "\" " +
			"\"" + componentName.GetFullPath() + "\"";

		AstadeChildProcess* aAstadeChildProcess = new AstadeChildProcess(aID, myTree);
		aAstadeChildProcess->Redirect();

		wxExecute(callName, wxEXEC_SYNC, aAstadeChildProcess);

		delete aElement;
	}

	myTree->UpdateAll(myTree->GetRootItem());
}