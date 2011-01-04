//~~ wxString CleanName(wxString name) [OMDgenerator] ~~
wxString bad(" :;.,/\\+-*<>()[]{}");
for (unsigned int ix = 0; ix < bad.length(); ++ix)
	name.Replace(bad.Mid(ix, 1), "_", true);
return name;
