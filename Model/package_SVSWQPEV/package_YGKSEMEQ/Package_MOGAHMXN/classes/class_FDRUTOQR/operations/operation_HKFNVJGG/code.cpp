wxString visibility = static_cast<AdeDestructor*>(myModelElement)->GetVisibility();

if (visibility == "private")
	return 24;

if (visibility == "protected")
	return 25;

return 23;