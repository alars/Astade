/* Re-Add this Class to all Components */
for (AdeElementIterator it = GetFirstComponent(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	wxFileConfig aConfig(wxEmptyString, wxEmptyString, anElement->GetFileName().GetFullPath());
	wxString mPath =  myFileName.GetFullPath(wxPATH_UNIX);
	mPath.Replace("/","|");

	if ((GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATECHART)
		aConfig.Write(wxString("Statecharts/") + mPath, true);
	else
		aConfig.Write(wxString("Classes/") + mPath, true);

	aConfig.Flush();

	delete(anElement);
}

AdeDirectoryElement::Move_Complete(parentPath);