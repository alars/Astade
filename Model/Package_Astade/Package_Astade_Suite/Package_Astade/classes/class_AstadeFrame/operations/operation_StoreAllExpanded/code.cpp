//~~ void StoreAllExpanded() [AstadeFrame] ~~

wxConfigBase::Get()->DeleteGroup(wxS("ExpandedNodes"));
myTree->StoreAllExpanded(myTree->GetRootItem());
wxConfigBase::Get()->Flush();
