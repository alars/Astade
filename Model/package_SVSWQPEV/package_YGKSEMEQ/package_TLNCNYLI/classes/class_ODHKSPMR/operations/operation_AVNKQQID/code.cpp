wxTreeItemId aID = myTree->GetSelection();
wxFileName path = myTree->GetItem(aID)->GetFileName();

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName OperationEditor = theConfig->Read("Tools/CodeEdit");

switch (event.GetId())
{
	case ID_EDITSPECPROLOG: path.SetFullName("prolog.h"); break;
	case ID_EDITIMPPROLOG: path.SetFullName("prolog.cpp"); break;
	case ID_EDITSPECEPILOG: path.SetFullName("epilog.h"); break;
	case ID_EDITIMPGEPILOG: path.SetFullName("epilog.cpp"); break;
}

if (!wxFile::Exists(path.GetFullPath().c_str()))
{
	wxFile(path.GetFullPath().c_str(),wxFile::write);

	AdeRevisionControlBase* theRevisionControl = AdeRevisionControlBase::GetRevisionControlObject();
	if (theRevisionControl->IsAddSupported())
	{
		int ret = theRevisionControl->Add(path);
		wxArrayString output = theRevisionControl->GetOutput();

		if (ret!=0)
		{
			wxString message;
			for(size_t i=0; i<output.GetCount(); i++) message += output[i]+"\n";
			wxMessageBox(message, "Operation failed",wxOK | wxICON_ERROR);
		}
	}
}

wxString callName = OperationEditor.GetFullPath()+" \""+path.GetFullPath()+"\"";

AstadeChildProcess* aAstadeChildProcess = new AstadeChildProcess(this);
wxExecute(callName, wxEXEC_ASYNC, aAstadeChildProcess);