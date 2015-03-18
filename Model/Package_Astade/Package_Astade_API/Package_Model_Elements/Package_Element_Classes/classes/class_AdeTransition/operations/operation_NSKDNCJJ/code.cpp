//~~ bool IsAllTransition() [AdeTransition] ~~
wxString TransitionType(myConfig->Read(wxS("Astade/TransitionType")));
return TransitionType == wxS("Internal");
