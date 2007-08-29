if (indexBase == -1) // not yet initialized
	InitializeIcons();

wxString visibility = static_cast<AdeDestructor*>(myModelElement)->GetVisibility();

if (visibility == "private")
	return indexBase + 2;

if (visibility == "protected")
	return indexBase +1;

return indexBase;