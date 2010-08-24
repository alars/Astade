//~~ wxString GetImpExtension() [AdeClass] ~~

wxString extension;
wxString language = codingLanguage();

if (language == CODE_CPlusPlus)
    extension = "cpp";
else if (language == CODE_C)
    extension = "c";
else if (language == CODE_JAVA)
    extension = "java";
else if (language == CODE_PYTHON)
    extension = "py";
else if (language == CODE_PHP)
    extension = "php";

return extension;
