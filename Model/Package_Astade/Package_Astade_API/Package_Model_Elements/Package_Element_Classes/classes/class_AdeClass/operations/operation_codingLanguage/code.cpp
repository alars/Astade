//~~ wxString codingLanguage() [AdeClass] ~~

wxString theLanguage = myConfig->Read("Astade/CodingLanguage","C++");

if (myConfig->Read("Astade/CCoded") == "yes")
    theLanguage = "Ansi C";

return theLanguage;
