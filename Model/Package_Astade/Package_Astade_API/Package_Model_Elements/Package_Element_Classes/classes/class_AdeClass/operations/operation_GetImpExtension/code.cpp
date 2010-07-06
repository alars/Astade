//~~ wxString GetImplementationExtension() [AdeClass] ~~

wxString extension;
wxString language = codingLanguage();

if (language == "C++")
    extension = "cpp";
else if (language == "Ansi C")
    extension = "c";
else if (language == "Java")
    extension = "java";
else if (language == "Python")
    extension = "py";
else if (language == "PHP")
    extension = "php";

return extension;
