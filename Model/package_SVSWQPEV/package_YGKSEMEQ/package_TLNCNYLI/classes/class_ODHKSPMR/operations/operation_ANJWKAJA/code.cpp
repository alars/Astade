copySource = myTree->GetSelection();
doCut = false;

/* copy file to clipboard as well */
if(wxTheClipboard->Open())
{
	wxTreeItemId aID = myTree->GetSelection();
	wxFileName aFilename = myTree->GetItem(aID)->GetFileName();
	wxFileDataObject* copyData = new wxFileDataObject();
	copyData->AddFile(aFilename.GetFullPath());
	wxTheClipboard->SetData(copyData);
	wxTheClipboard->Close();
}
else
{
	wxLogMessage("Cannot open the Clipboard!");
}