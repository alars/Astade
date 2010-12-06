//~~ wxString GetImpExtension() [AdeStatechart] ~~

wxString extension = wxS("cpp");
wxString coder = GetCoderSuffix();

if (coder == wxS("C"))
	extension = wxS("c");
else if (coder == wxS("ACF"))
	extension = wxS("c");

return extension;
