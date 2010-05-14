wxFileName modelPath(GetModelPath());

/* Remove this Class from all Components */
for (AdeElementIterator it = GetFirstComponent(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();

	wxFileConfig aConfig(wxEmptyString, wxEmptyString, anElement->GetFileName().GetFullPath());

	wxFileName aFileName(myFileName);
	aFileName.MakeRelativeTo(modelPath.GetPath());
	wxString mPath = aFileName.GetFullPath(wxPATH_UNIX);

	mPath.Replace(wxS("/"), wxS("|"));

	if ((GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATECHART)
		aConfig.DeleteEntry(wxS("Statecharts/") + mPath);
	else
		aConfig.DeleteEntry(wxS("Classes/") + mPath);

	aConfig.Flush();

	delete(anElement);
}
