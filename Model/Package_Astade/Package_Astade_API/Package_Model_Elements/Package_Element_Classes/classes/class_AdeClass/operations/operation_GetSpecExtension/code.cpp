//~~ wxString GetSpecExtension() [AdeClass] ~~

wxString extension;
wxString language = codingLanguage();

if (language == "C++")
    extension = "h";
else if (language == "Ansi C")
    extension = "h";
else if (language == "Java")
    extension = "h";
else if (language == "Python")
    extension = "pym";
else if (language == "PHP")
    extension = "h";

return extension;
