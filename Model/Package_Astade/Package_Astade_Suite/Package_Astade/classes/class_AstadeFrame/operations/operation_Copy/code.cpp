//~~ void Copy(wxCommandEvent& event) [AstadeFrame] ~~

myTree->GetItemObject(myTree->GetSelection())->SetToGlobalCopySource();
doCut = false;

/* copy file to clipboard as well */
if (wxTheClipboard->Open())
{
	wxTreeItemId anID = myTree->GetSelection();
	wxFileName aFilename = myTree->GetItem(anID)->GetFileName();
	wxFileDataObject* copyData = new wxFileDataObject();
	copyData->AddFile(aFilename.GetFullPath());
	wxTheClipboard->SetData(copyData);
	wxTheClipboard->Close();
}
else
{
	wxLogMessage(wxS("Cannot open the Clipboard!"));
}
