event.Allow();
//copySource = myTree->GetSelection();
wxTreeItemId aID = myTree->GetSelection();
wxFileName aFilename = myTree->GetItem(aID)->GetFileName();
wxFileDataObject dragData;
dragData.AddFile(aFilename.GetFullPath());
wxDropSource dragSource(this);
dragSource.SetData(dragData);
dragSource.DoDragDrop();