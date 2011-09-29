//~~ void Paste(wxCommandEvent& event) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetSelection();

if (!myTree->GetItemObject(anID)->OfferPaste())
    return;

wxFileName destination = myTree->GetItem(anID)->GetFileName();

AdeModelElement* anElement = AstadeTreeItemBase::GetGlobalCopySource()->GetModelElement();

wxFileName parentPath;
parentPath.AssignDir(destination.GetPath());			   //directory where to make copy for whatever element from Astade tree.

if (doCut)
{
    anElement->Move(parentPath);
    myTree->AppendItem(anID, anElement->GetFileName());
    myTree->Delete(AstadeTreeItemBase::GetGlobalCopySource()->GetId());
}
else
{
    wxFileName newFile = anElement->CreateCopy(parentPath);                          //Applying polymorphism CreateCopy(...). An element should define this function.
    myTree->AppendItem(anID, newFile);
}

myTree->GetItemObject(anID)->Touch();
