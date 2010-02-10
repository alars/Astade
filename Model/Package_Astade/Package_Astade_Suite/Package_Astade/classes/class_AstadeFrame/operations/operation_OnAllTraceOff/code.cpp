wxConfigBase::Get()->DeleteGroup("TreeView/TraceClasses/");
wxConfigBase::Get()->Flush();
myTree->UpdateAll(myTree->GetRootItem());