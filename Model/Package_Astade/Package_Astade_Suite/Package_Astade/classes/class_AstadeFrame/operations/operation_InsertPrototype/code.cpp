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
	wxString str;
	
	// Signature already OK?
	if (theCode.GetFirstLine() == signature) 
		return;
	
	for (str = theCode.GetFirstLine(); !theCode.Eof(); str = theCode.GetNextLine())
	{
		while (str.Find("//~~") == 0)
		{
			theCode.RemoveLine(theCode.GetCurrentLine());
			str = theCode.GetFirstLine();
		}
	}
	theCode.InsertLine(signature.c_str(), 0);
	
	theCode.Write();
}
