//~~ void Features(wxCommandEvent& event) [AstadeFrame] ~~

wxConfigBase* theConfig = wxConfigBase::Get();

wxFileName featureEditor(theConfig->Read("Tools/FeatureEdit"));

wxTreeItemId anID = myTree->GetSelection();

wxString callName = featureEditor.GetFullPath() + " \"" + myTree->GetItem(anID)->GetFileName().GetFullPath() + "\"";

//** this is for keyboard short cut
wxString ext = myTree->GetItem(anID)->GetFileName().GetExt();

if (ext == "ini")  //Don't bother to check if the element is not belong to "ModelNode.ini"
{
	AdeModelElement* anElement = myTree->GetItem(anID); //Getting the object from selection

	if (anElement->hasFeatures())
	{
		wxExecute(callName, wxEXEC_ASYNC, new AstadeChildProcess(this));
	}
}
