wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();

wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName activeComponentName = theConfig->Read("TreeView/ActiveComponent");
wxFileName modelPath = theConfig->Read("TreeView/ModelPath");
parentPath.MakeRelativeTo(modelPath.GetPath());

wxFileConfig aConfig(wxEmptyString,wxEmptyString,activeComponentName.GetFullPath());
aConfig.DeleteEntry(wxString("Classes/") + parentPath.GetFullPath());
aConfig.Write("Astade/LastChanged",wxGetUTCTime());
aConfig.Flush();

myTree->UpdateItem(aID);