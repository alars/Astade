//~~ wxString codingLanguage() [AdeClass] ~~

wxString theLanguage;
if (!myConfig->Read(wxS("Astade/CodingLanguage"), &theLanguage))
	theLanguage = myConfig->Read(wxS("Astade/CCoded")) == wxS("yes") ? CODE_C : CODE_CPlusPlus;
if (theLanguage == wxS("Ansi C"))
	theLanguage = CODE_C;

return theLanguage;
