if (indexBase == -1) // not yet initialized
	InitializeIcons();

int ret = indexBase;

wxString visibility = static_cast<AdeAttribute*>(myModelElement)->GetVisibility();

if (visibility == "private")
	ret += 4;

if (visibility == "protected")
	ret += 2;

if (static_cast<AdeAttribute*>(myModelElement)->IsConst())
	ret++;

return ret;