wxTreeItemId aID = myTree->GetSelection();
wxFileName parentPath = myTree->GetItem(aID)->GetFileName();
wxConfigBase* theConfig = wxConfigBase::Get();
theConfig->Write("TreeView/ActiveComponent",parentPath.GetFullPath());
theConfig->Flush();
myTree->UpdateAll();
