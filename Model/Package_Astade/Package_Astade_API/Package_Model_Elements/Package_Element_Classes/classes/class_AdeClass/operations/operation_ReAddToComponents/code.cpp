wxFileName modelPath(GetModelPath());

/* Re-Add this Class to all Components */
for (AdeElementIterator it = GetFirstComponent(); it != end(); ++it)
{
	AdeModelElement* anElement = it.CreateNewElement();
	wxFileConfig aConfig(wxEmptyString, wxEmptyString, anElement->GetFileName().GetFullPath());

	wxFileName aFileName(myFileName);
	aFileName.MakeRelativeTo(modelPath.GetPath());
	wxString mPath =  aFileName.GetFullPath(wxPATH_UNIX);

	mPath.Replace(wxS("/"), wxS("|"));

	if ((GetType() & ITEM_TYPE_MASK) == ITEM_IS_STATECHART)
		aConfig.Write(wxS("Statecharts/") + mPath, true);
	else
		aConfig.Write(wxS("Classes/") + mPath, true);

	aConfig.Flush();

	delete(anElement);
}
