//~~ void OnDrag(wxTreeEvent& event) [AstadeFrame] ~~

int flags = 0;
wxTreeItemId anID = myTree->HitTest(myTree->ScreenToClient(wxGetMousePosition()), flags);
if (!anID.IsOk())
	return;

wxFileName aFilename = myTree->GetItem(anID)->GetFileName();
wxFileDataObject dragData;
dragData.AddFile(aFilename.GetFullPath());
wxDropSource dropSource(dragData, this);
dropSource.DoDragDrop(); // wxDrag_AllowMove
