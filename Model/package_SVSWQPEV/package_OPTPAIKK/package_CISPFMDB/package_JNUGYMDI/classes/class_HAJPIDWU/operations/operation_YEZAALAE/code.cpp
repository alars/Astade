wxString visibility = GetVisibility();

if (visibility == "private")
	return 11;

if (visibility == "protected")
	return 12;

return 7;