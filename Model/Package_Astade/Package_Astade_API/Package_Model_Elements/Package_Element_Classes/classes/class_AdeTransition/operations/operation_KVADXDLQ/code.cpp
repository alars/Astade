//~~ bool IsTerminatelTransition() [AdeTransition] ~~
wxString TransitionType(myConfig->Read(wxS("Astade/TransitionType")));
return TransitionType == wxS("Terminate");
