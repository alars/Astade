myTree->UpdateItem(event.GetOldItem());
myTree->UpdateItem(event.GetItem());

wxConfigBase* theConfig = wxConfigBase::Get();
wxString modelPath = theConfig->Read("TreeView/ModelPath");

wxFileName aFileName = myTree->GetItem(event.GetItem())->GetFileName();
aFileName.MakeRelativeTo(modelPath);
myStatusBar.PushStatusText(aFileName.GetFullPath());
