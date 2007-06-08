wxConfigBase* theConfig = wxConfigBase::Get();
wxFileName modelPath;
modelPath.AssignDir(theConfig->Read("TreeView/ModelPath"));

AdeDirectoryElement::Move_Complete(parentPath); // Recursively complete all children;

/* Re-Add this Class to all Components */
for (AdeElementIterator it = GetFirstComponent(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	wxFileConfig aConfig(wxEmptyString, wxEmptyString, anElement->GetFileName().GetFullPath());

	wxFileName aFileName(myFileName);
	aFileName.MakeRelativeTo(modelPath.GetPath());
	wxString mPath =  aFileName.GetFullPath(wxPATH_UNIX);

	mPath.Replace("/","|");

	if ((GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATECHART)
		aConfig.Write(wxString("Statecharts/") + mPath, true);
	else
		aConfig.Write(wxString("Classes/") + mPath, true);

	aConfig.Flush();

	delete(anElement);
}