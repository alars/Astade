wxString visibility = GetVisibility();

if (visibility == "private")
	return 18;

if (visibility == "protected")
	return 19;

return 8;