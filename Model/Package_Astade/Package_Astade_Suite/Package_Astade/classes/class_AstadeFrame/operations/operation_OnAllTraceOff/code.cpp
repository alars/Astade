//~~ void OnAllTraceOff(wxCommandEvent& event) [AstadeFrame] ~~

wxConfigBase::Get()->DeleteGroup(wxS("TreeView/TraceClasses/"));
wxConfigBase::Get()->Flush();
myTree->UpdateAll(myTree->GetRootItem());
