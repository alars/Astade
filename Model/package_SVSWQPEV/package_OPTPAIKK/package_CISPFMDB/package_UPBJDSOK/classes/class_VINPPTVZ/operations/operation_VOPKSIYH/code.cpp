if (!theFilenameList.empty())
{
	wxFileName theName(theFilenameList.front());
	return AdeModelElement::CreateNewElement(theName);
}
return new AdeModelElement(wxFileName());
