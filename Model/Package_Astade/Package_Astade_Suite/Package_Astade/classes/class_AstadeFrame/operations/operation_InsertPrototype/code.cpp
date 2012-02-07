//~~ void InsertPrototype(const wxTreeItemId& treeItem) [AstadeFrame] ~~

wxTreeItemId anID = myTree->GetItemParent(treeItem);
AdeOperationBase* theOperation = dynamic_cast<AdeOperationBase*>(myTree->GetItem(anID));

// We do this for operations only
if (theOperation == 0)
	return;

wxTreeItemId operationsID = myTree->GetItemParent(anID);
wxTreeItemId classID = myTree->GetItemParent(operationsID);
AdeClass* theClass = dynamic_cast<AdeClass*>(myTree->GetItem(classID));

wxFileName path = myTree->GetItem(treeItem)->GetFileName();

wxTextFile theCode(path.GetFullPath());
if (theCode.Exists())
	theCode.Open();

if (theCode.IsOpened())
{
	wxString signature(wxS("//~~ ") + theOperation->GetLabel());
	if (theClass)
		signature += wxS(" [") + theClass->GetLabel() + wxS("]");
	signature += wxS(" ~~");

	wxString str(theCode.GetFirstLine());
	
	// Signature already OK?
	if (str == signature) 
		return;
	
	if (str.Find(wxS("//~~ ")) == 0)
		theCode.RemoveLine(0);
	theCode.InsertLine(signature, 0);
	
	theCode.Write();
}
