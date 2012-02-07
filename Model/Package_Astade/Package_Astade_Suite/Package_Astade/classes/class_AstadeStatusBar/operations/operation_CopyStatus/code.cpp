//~~ void CopyStatus(wxEvent& event) [AstadeStatusBar] ~~

/* copy status-text to clipboard */
if (wxTheClipboard->Open())
{
	wxTreeItemId anID = myTree->GetSelection();
	wxFileName aFilename = myTree->GetItem(anID)->GetFileName();
	if (aFilename.GetFullName() == wxS("ModelNode.ini"))
		aFilename.SetFullName(wxEmptyString);
	if (event.GetId() == ID_COPYSTATUS)
		aFilename.MakeAbsolute();
	else
		aFilename.MakeRelativeTo(AdeModelElement::GetModelPath().GetPath());
	wxTextDataObject* copyData = new wxTextDataObject();
	copyData->SetText(aFilename.GetFullPath());
	wxTheClipboard->SetData(copyData);
	wxTheClipboard->Close();
}
else
{
	wxLogMessage(wxS("Cannot open the Clipboard!"));
}
