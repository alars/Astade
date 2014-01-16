//~~ void OnTraceOnOff(wxCommandEvent& event) [AstadeFrame] ~~
wxTreeItemId anId = myTree->GetSelection();
AdeModelElement* element = myTree->GetItem(anId);
AdeClass* aClass = dynamic_cast<AdeClass*>(element);

if (aClass!=NULL)
{
    aClass->SetIsTraced(event.GetId() == ID_TRACE_ON);
    aClass->Touch();
}

myTree->UpdateItem(anId);
myTree->UpdateAll(myTree->GetRootItem());
