myTree->UpdateItem(event.GetOldItem());
myTree->UpdateItem(event.GetItem());

wxTreeItemId anItem = event.GetItem();

if (!anItem.IsOk())
	return;

AdeModelElement* anElement = myTree->GetItem(anItem);

if (anElement == 0)
	return;

wxFileName elementFileName = anElement->GetFileName();

wxString newText = elementFileName.GetFullPath();

if (newText.size() > 127)
	newText = "..." + newText.Right(124);

SetStatusText(newText,1);
