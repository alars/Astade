//~~ wxString getNamespace(wxArrayString aNamespace) [ResourceEdit] ~~

wxString theNamespace;
for (unsigned int ix = 0; ix < aNamespace.GetCount(); ++ix)
	theNamespace += aNamespace[ix] + wxS("::");
return theNamespace;
