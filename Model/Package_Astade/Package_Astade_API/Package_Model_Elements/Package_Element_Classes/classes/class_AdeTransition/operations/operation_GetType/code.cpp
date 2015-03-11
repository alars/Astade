//~~ long GetType() [AdeTransition] ~~
wxString TransitionType = myConfig->Read(wxS("Astade/TransitionType"));

if (TransitionType == wxS("Normal"))
	return AdeFileElement::GetType() + 2;

if (TransitionType == wxS("Self"))
	return AdeFileElement::GetType() + 1;

return AdeFileElement::GetType() + 0;
