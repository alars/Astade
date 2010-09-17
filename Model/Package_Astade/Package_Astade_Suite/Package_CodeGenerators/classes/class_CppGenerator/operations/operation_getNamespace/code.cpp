//~~ wxString getNamespace(wxArrayString aNamespace) [CppGenerator] ~~

wxString theNamespace;
for (unsigned int ix = 0; ix < aNamespace.GetCount(); ++ix)
	theNamespace += aNamespace[ix] + "::";
return theNamespace;
