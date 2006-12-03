/* Remove this Class from all Components */
for (AdeElementIterator it = GetFirstComponent(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	
	wxFileConfig aConfig(wxEmptyString, wxEmptyString, anElement->GetFileName().GetFullPath());
	wxString mPath =  myFileName.GetFullPath(wxPATH_UNIX);
	mPath.Replace("/","|");

	if ((GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATECHART)
		aConfig.DeleteEntry(wxString("Statecharts/") + mPath);
	else
		aConfig.DeleteEntry(wxString("Classes/") + mPath);

	aConfig.Flush();

	delete(anElement);
}

AdeDirectoryElement::Move_Prepare(parentPath);