//~~ wxString GetFullName() [AdeClass] ~~

wxArrayString aNamespace = getNamespace();
wxString theNamespace;
for (unsigned int ix = 0; ix < aNamespace.GetCount(); ++ix)
	theNamespace += aNamespace[ix] + wxS("::");
return theNamespace+GetName();
