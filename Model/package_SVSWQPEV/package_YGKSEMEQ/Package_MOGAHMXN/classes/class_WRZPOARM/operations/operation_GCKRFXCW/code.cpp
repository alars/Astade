if (indexBase == -1) // not yet initialized
	InitializeIcons();

wxString label = static_cast<AdeFiles*>(myModelElement)->GetLabel();

if (label == "manual")
	return indexBase + 1;
else
	return indexBase;