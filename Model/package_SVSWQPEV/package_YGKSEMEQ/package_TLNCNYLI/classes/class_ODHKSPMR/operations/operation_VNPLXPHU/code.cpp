wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName coder(theConfig->Read("Tools/Coder"));

wxTreeItemId aID = myTree->GetSelection();

wxFileName componentName(theConfig->Read("TreeView/ActiveComponent"));
componentName.AppendDir("auto");

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
	wxProgressDialog progressDialog("Regenerate", "Starting ...", count, this);
	int done = 0;

	for (AdeElementIterator it = theComponent.GetFirstBelongingClass();
		 it!=theComponent.end();
		 ++it)
	{
		AdeModelElement* aElement = it.CreateNewElement();

		progressDialog.Update( done, aElement->GetLabel());

		wxThread::Sleep(100);

		++done;


		delete aElement;
	}
}
/*
component.AppendDir("auto");

component.SetName(myTree->GetItem(aID)->GetName());
component.SetExt("cpp");

wxString callName = "\"" + coder.GetFullPath() + "\" " +
	"\"" + myTree->GetItem(aID)->GetFileName().GetFullPath() + "\" " +
	"\"" + component.GetFullPath() + "\"";

AstadeChildProcess* aAstadeChildProcess = new AstadeChildProcess(aID, myTree);
aAstadeChildProcess->Redirect();

wxExecute(callName, wxEXEC_ASYNC, aAstadeChildProcess);
*/