if (indexBase == -1) // not yet initialized
	InitializeIcons();

int ret = indexBase;

wxString visibility = static_cast<AdeOperation*>(myModelElement)->GetVisibility();

if (visibility == "private")
	ret += 4;

if (visibility == "protected")
	ret += 2;

if (static_cast<AdeOperation*>(myModelElement)->IsConst())
	ret++;

return ret;