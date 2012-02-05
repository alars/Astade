//~~ wxString GetImpExtension() [AdeClass] ~~

wxString extension;
wxString language = codingLanguage();

if (language == CODE_CPlusPlus)
    extension = wxS("cpp");
else if (language == CODE_C)
    extension = wxS("c");
else if (language == CODE_JAVA)
    extension = wxS("java");
else if (language == CODE_PYTHON)
    extension = wxS("py");
else if (language == CODE_PHP)
    extension = wxS("php");

return extension;
