//~~ wxString GetSpecExtension() [AdeClass] ~~

wxString extension;
wxString language = codingLanguage();

if (language == CODE_CPlusPlus)
    extension = "h";
else if (language == CODE_C)
    extension = "h";
else if (language == CODE_JAVA)
    extension = "h";
else if (language == CODE_PYTHON)
    extension = "pym";
else if (language == CODE_PHP)
    extension = "h";

return extension;
