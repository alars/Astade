wxConfigBase* theConfig = wxConfigBase::Get();

AddToRecentList(modelpath);
theConfig->Write("TreeView/ModelPath", modelpath.GetFullPath());
theConfig->Write("TreeView/ActiveComponent", "none");
theConfig->Flush();

wxSize oldSize = myTree->GetSize();
AstadeTree* oldTree = myTree;
myTree = new AstadeTree(this);
AstadeTreeItemBase::SetOurTree(*myTree);
delete oldTree;
myTree->SetSize(oldSize);

delete myMakeOutput;
myMakeOutput = new AstadeMakeOutput(myTree);

UpdateToolbar();
dynamic_cast<AstadeStatusBar*>(myStatusBar)->SetTree(myTree);
SetStatusText(wxEmptyString, 1);
