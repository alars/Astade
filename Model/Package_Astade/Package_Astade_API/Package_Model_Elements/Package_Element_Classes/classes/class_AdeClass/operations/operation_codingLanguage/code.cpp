//~~ wxString codingLanguage() [AdeClass] ~~

wxString theLanguage;
if (!wxConfigBase::Get()->Read("Astade/CodingLanguage", &theLanguage))
	theLanguage = wxConfigBase::Get()->Read("Astade/CCoded") == "yes" ? CODE_C : CODE_CPlusPlus;
if (theLanguage == "Ansi C")
	theLanguage = CODE_C;

return theLanguage;
