wxString visibility = GetVisibility();

if (visibility == "private")
	return 21;

if (visibility == "protected")
	return 22;

return 20;