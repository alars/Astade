if (!theFilenameList.empty())
{
	wxFileName theName = theFilenameList.front();

	if (theName.GetFullName()!="Desktop.ini")
		return new AdeFile(theName);
}

return new AdeModelElement(wxFileName());