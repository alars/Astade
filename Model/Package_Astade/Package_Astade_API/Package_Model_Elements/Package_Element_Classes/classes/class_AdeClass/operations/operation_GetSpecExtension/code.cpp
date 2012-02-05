//~~ wxString GetSpecExtension() [AdeClass] ~~

wxString extension;
wxString language = codingLanguage();

if (language == CODE_CPlusPlus)
    extension = wxS("h");
else if (language == CODE_C)
    extension = wxS("h");
else if (language == CODE_JAVA)
    extension = wxS("h");
else if (language == CODE_PYTHON)
    extension = wxS("pym");
else if (language == CODE_PHP)
    extension = wxS("h");

return extension;
