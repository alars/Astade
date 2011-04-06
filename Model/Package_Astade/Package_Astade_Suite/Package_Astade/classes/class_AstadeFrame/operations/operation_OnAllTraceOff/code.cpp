//~~ void OnAllTraceOff(wxCommandEvent& event) [AstadeFrame] ~~
wxConfigBase::Get()->DeleteGroup("TreeView/TraceClasses/");
wxConfigBase::Get()->Flush();
myTree->UpdateAll(myTree->GetRootItem());