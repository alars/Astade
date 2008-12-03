		wxConfigBase* theConfig = wxConfigBase::Get();

wxFileName featureEditor(theConfig->Read("Tools/FeatureEdit"));

wxTreeItemId aID = myTree->GetSelection();

wxString callName = featureEditor.GetFullPath()+" \""+myTree->GetItem(aID)->GetFileName().GetFullPath()+"\"";

//** this is for keyboard short cut
wxString ext = myTree->GetItem(aID)->GetFileName().GetExt();
//wxString fullName = myTree->GetItem(aID)->GetFileName().GetFullName();
//wxString fullPath = myTree->GetItem(aID)->GetFileName().GetFullPath();

if( ext == "ini")  //Don't bother to check if the element is not belong to "ModelNode.ini"
//**
{
	AdeModelElement* aElement = myTree->GetItem(aID); //Getting the object from selection

	if(aElement->hasFeatures())
	{
		wxExecute(callName, wxEXEC_ASYNC, new AstadeChildProcess(this));
	}

}
