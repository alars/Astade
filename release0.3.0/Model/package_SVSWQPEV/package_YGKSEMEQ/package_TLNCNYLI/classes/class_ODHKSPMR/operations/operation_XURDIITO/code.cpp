wxConfigBase* theConfig = wxConfigBase::Get();

wxFileName featureEditor(theConfig->Read("Tools/FeatureEdit"));

wxTreeItemId aID = myTree->GetSelection();

wxString callName = featureEditor.GetFullPath()+" \""+myTree->GetItem(aID)->GetFileName().GetFullPath()+"\"";

wxExecute(callName, wxEXEC_ASYNC, new AstadeChildProcess(aID,myTree));
