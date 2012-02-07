//~~ void DoGenerate(bool regenerate = false) [AstadeFrame] ~~

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName ccoder(theConfig->Read(wxS("Tools/CCoder")));
wxFileName coder(theConfig->Read(wxS("Tools/Coder")));
wxFileName statechartCoder(theConfig->Read(wxS("Tools/StatechartCoder")));

wxFileName componentName(theConfig->Read(wxS("TreeView/ActiveComponent")));

AdeComponent theComponent(componentName);
componentName.AppendDir(wxS("auto"));

AdeElementIterator it;
int count = 0;
for (it = theComponent.GetFirstBelongingClass(); it != theComponent.end(); ++it)
{
	AdeClass* aClass = dynamic_cast<AdeClass*>(it.CreateNewElement());
	assert(aClass);
	if (regenerate || aClass->IsChanged())
		count++;
	delete aClass;
}

for (it = theComponent.GetFirstBelongingStatechart(); it != theComponent.end(); ++it)
{
	AdeClass* aClass = dynamic_cast<AdeClass*>(it.CreateNewElement());
	assert(aClass);
	if (regenerate || aClass->IsChanged())
		count++;
	delete aClass;
}

if (count > 0)
{
	wxBusyCursor wait;
	wxProgressDialog progressDialog(wxS("Regenerate"), wxS("Starting ..."), count, this, wxPD_AUTO_HIDE | wxPD_ELAPSED_TIME | wxPD_ESTIMATED_TIME | wxPD_REMAINING_TIME | wxPD_SMOOTH);
	count = 0;

	// Generating the classes
	for (it = theComponent.GetFirstBelongingClass(); it != theComponent.end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		assert(anElement);
		AdeClass* theClass = dynamic_cast<AdeClass*>(anElement);
		assert(theClass);

		if (theClass && (regenerate || theClass->IsChanged()))
		{
			progressDialog.Update(count++, anElement->GetName());

			componentName.SetName(anElement->GetName());

			wxString callName;

			wxFileName aFile = anElement->GetFileName();
			aFile.MakeAbsolute();
			if (theClass->codingLanguage() == CODE_C)
			{
				callName = wxS("\"") + ccoder.GetFullPath() + wxS("\" ") +
						wxS("\"") + aFile.GetFullPath() + wxS("\" ") +
						wxS("\"") + componentName.GetFullPath() + wxS("\"");
			}
			else
			{
				callName = wxS("\"") + coder.GetFullPath() + wxS("\" ") +
						wxS("\"") + aFile.GetFullPath() + wxS("\" ") +
						wxS("\"") + componentName.GetFullPath() + wxS("\"");
			}
			componentName.SetExt(theClass->GetImpExtension());

			AstadeChildProcess* anAstadeChildProcess = new AstadeChildProcess(this);
			anAstadeChildProcess->Redirect();
			wxExecute(callName, wxEXEC_SYNC, anAstadeChildProcess);
			delete anAstadeChildProcess;
		}

		delete anElement;
	}

	// Generating the statecharts
	for (it = theComponent.GetFirstBelongingStatechart(); it != theComponent.end(); ++it)
	{
		AdeModelElement* anElement = it.CreateNewElement();
		assert(anElement);
		AdeStatechart* aStateChart = dynamic_cast<AdeStatechart*>(anElement);

		assert(aStateChart);

		if (regenerate || aStateChart->IsChanged())
		{
			progressDialog.Update(count++, anElement->GetName());

			componentName.SetName(anElement->GetName());
			componentName.SetExt(wxS("cpp"));

			wxFileName aFile = anElement->GetFileName();
			aFile.MakeAbsolute();		

			if (aStateChart == 0)
				wxLogFatalError(wxS("Cannot generate because the item is no Statechart"));

			// Add the coder suffix to the name
			wxFileName theCoder(statechartCoder);
			wxString coderBaseName = theCoder.GetName();
			coderBaseName += aStateChart->GetCoderSuffix();
			theCoder.SetName(coderBaseName);

			wxString callName = wxS("\"") + theCoder.GetFullPath() + wxS("\" ") +
					wxS("\"") + aFile.GetFullPath() + wxS("\" ") +
					wxS("\"") + componentName.GetFullPath() + wxS("\"");
	
			AstadeChildProcess* anAstadeChildProcess = new AstadeChildProcess(this);
			anAstadeChildProcess->Redirect();
			wxExecute(callName, wxEXEC_SYNC, anAstadeChildProcess);
			delete anAstadeChildProcess;
		}

		delete anElement;
	}

	myTree->UpdateAll(myTree->GetRootItem());
}
