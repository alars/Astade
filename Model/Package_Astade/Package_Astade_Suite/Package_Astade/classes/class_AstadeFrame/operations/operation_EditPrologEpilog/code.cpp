//~~ void EditPrologEpilog(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();
AdeModelElement* anElement = myTree->GetItem(anID);
wxFileName path = anElement->GetFileName();

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName OperationEditor = theConfig->Read(wxS("Tools/CodeEdit"));

bool spec = true;
switch (event.GetId())
{
case ID_EDITSPECPROLOG:
	path.SetFullName(wxS("prolog.h"));
	break;

case ID_EDITIMPPROLOG:
	spec = false;
	path.SetFullName(wxS("prolog.cpp"));
	break;

case ID_EDITSPECEPILOG:
	path.SetFullName(wxS("epilog.h"));
	break;

case ID_EDITIMPGEPILOG:
	spec = false;
	path.SetFullName(wxS("epilog.cpp"));
	break;
}

if (!wxFile::Exists(path.GetFullPath()))
{
	// default prologue doesn't exist, look for "prolog.<language_ext>"
	AdeClass* aClass = dynamic_cast<AdeClass*>(anElement);
	if (aClass)
		path.SetExt(spec ? aClass->GetSpecExtension() : aClass->GetImpExtension());
	if (!wxFile::Exists(path.GetFullPath()))
	{
		wxFile(path.GetFullPath(), wxFile::write);

		AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
		if (theRevisionControl->IsAddSupported())
		{
			int ret = theRevisionControl->Add(path);
			wxArrayString output = theRevisionControl->GetOutput();

			if (ret != 0)
			{
				wxString message;
				for (size_t i = 0; i < output.GetCount(); i++)
					message += output[i] + wxS("\n");
				wxMessageBox(message, wxS("Operation failed"), wxOK | wxICON_ERROR);
			}
		}
		myTree->LoadSubnodes(anID);
		myTree->AppendExistingItem(anID, path);
	}
}

myTree->ShowNode(path);

wxString callName = OperationEditor.GetFullPath() + wxS(" \"") + path.GetFullPath() + wxS("\"");

AstadeChildProcess* anAstadeChildProcess = new AstadeChildProcess(this);
wxExecute(callName, wxEXEC_ASYNC, anAstadeChildProcess);
