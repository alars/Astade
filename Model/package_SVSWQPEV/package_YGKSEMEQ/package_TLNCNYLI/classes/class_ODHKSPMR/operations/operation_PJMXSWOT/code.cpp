wxConfigBase::Get()->DeleteGroup("ExpandedNodes");
myTree->StoreAllExpanded(myTree->GetRootItem());
wxConfigBase::Get()->Flush();