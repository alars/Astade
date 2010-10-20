//~~ wxString codingLanguage() [AdeClass] ~~

wxString theLanguage;
if (!myConfig->Read("Astade/CodingLanguage", &theLanguage))
	theLanguage = myConfig->Read("Astade/CCoded") == "yes" ? CODE_C : CODE_CPlusPlus;
if (theLanguage == "Ansi C")
	theLanguage = CODE_C;

return theLanguage;
