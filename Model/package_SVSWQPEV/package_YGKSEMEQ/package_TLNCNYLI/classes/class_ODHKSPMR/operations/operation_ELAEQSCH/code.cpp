myTree->UpdateItem(event.GetOldItem());
myTree->UpdateItem(event.GetItem());

wxString newText = myTree->GetItem(event.GetItem())->GetFileName().GetFullPath();

if (newText.size() > 127)
	newText = "..." + newText.Right(124);

SetStatusText(newText);