/* copy file to clipboard as well */
if(wxTheClipboard->Open())
{
	wxTreeItemId aID = myTree->GetSelection();
	wxFileName aFilename = myTree->GetItem(aID)->GetFileName();
	wxTextDataObject* copyData = new wxTextDataObject();
	copyData->SetText(aFilename.GetFullPath());
	wxTheClipboard->SetData(copyData);
	wxTheClipboard->Close();
}
else
{
	wxLogMessage("Cannot open the Clipboard!");
}