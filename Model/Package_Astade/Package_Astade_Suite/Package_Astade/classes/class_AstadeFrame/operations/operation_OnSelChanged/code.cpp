//~~ void OnSelChanged(wxTreeEvent& event) [AstadeFrame] ~~

myTree->UpdateItem(event.GetOldItem());
myTree->UpdateItem(event.GetItem());

wxTreeItemId anItem = event.GetItem();

if (!anItem.IsOk())
	return;

AdeModelElement* anElement = myTree->GetItem(anItem);

if (anElement == 0)
	return;

wxFileName elementFileName(anElement->GetFileName());
if (elementFileName.GetFullName() == "ModelNode.ini")
	elementFileName.SetFullName(wxEmptyString);
wxString newText(elementFileName.GetFullPath());

#if !wxCHECK_VERSION(2,9,1)
if (newText.size() > 127)
	newText = "..." + newText.Right(124);
#endif

SetStatusText(newText, 1);
