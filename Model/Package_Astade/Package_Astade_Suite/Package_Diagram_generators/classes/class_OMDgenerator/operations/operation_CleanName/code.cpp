//~~ wxString CleanName(wxString name) [OMDgenerator] ~~

wxString bad(wxS(" :;.,/\\+-*<>()[]{}"));
for (unsigned int ix = 0; ix < bad.length(); ++ix)
	name.Replace(bad.Mid(ix, 1), wxS("_"), true);
return name;
