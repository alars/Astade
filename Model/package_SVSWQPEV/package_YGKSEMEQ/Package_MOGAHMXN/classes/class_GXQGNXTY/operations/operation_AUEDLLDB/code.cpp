if (indexBase == -1) // not yet initialized
	InitializeIcons();

wxString visibility = static_cast<AdeConstructor*>(myModelElement)->GetVisibility();

int ret = indexBase;

if (visibility == "private")
	ret += 2;

if (visibility == "protected")
	ret += 1;

if (static_cast<AdeConstructor*>(myModelElement)->IsInline())
	ret += 3;

return ret;