//~~ void Features(wxCommandEvent& event) [AstadeFrame] ~~

wxConfigBase* theConfig = wxConfigBase::Get();

wxFileName featureEditor(theConfig->Read(wxS("Tools/FeatureEdit")));

wxTreeItemId anID = myTree->GetSelection();

wxString callName(featureEditor.GetFullPath() + wxS(" \"") + myTree->GetItem(anID)->GetFileName().GetFullPath() + wxS("\""));

//** this is for keyboard shortcut
wxString ext = myTree->GetItem(anID)->GetFileName().GetExt();

if (ext == wxS("ini"))  //Don't bother to check if the element is not belong to "ModelNode.ini"
{
	AdeModelElement* anElement = myTree->GetItem(anID); //Getting the object from selection

	if (anElement->hasFeatures())
	{
		wxExecute(callName, wxEXEC_ASYNC, new AstadeChildProcess(this));
	}
}
