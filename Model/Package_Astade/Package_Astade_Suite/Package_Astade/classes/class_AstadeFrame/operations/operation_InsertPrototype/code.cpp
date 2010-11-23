//~~ void InsertPrototype(const wxTreeItemId& treeItem) [AstadeFrame] ~~

wxTreeItemId aID = myTree->GetItemParent(treeItem);
AdeOperationBase* theOperation = dynamic_cast<AdeOperationBase*>(myTree->GetItem(aID));

// We do this for operations only
if (theOperation == 0)
	return;

wxTreeItemId operationsID = myTree->GetItemParent(aID);
wxTreeItemId classID = myTree->GetItemParent(operationsID);
AdeClass* theClass = dynamic_cast<AdeClass*>(myTree->GetItem(classID));

wxFileName path = myTree->GetItem(treeItem)->GetFileName();

wxTextFile theCode(path.GetFullPath());
if (theCode.Exists())
	theCode.Open();

if (theCode.IsOpened())
{
	wxString signature = "//~~ " + theOperation->GetLabel();
	if (theClass)
		signature += " [" + theClass->GetLabel() + "]";
	signature += " ~~";

	wxString str(theCode.GetFirstLine());
	
	// Signature already OK?
	if (str == signature) 
		return;
	
	if (str.Find("//~~ ") == 0)
		theCode.RemoveLine(0);
	theCode.InsertLine(signature.c_str(), 0);
	
	theCode.Write();
}
