LanguageInfo const* curInfo;

// determine language from filepatterns
int languageNr;
for (languageNr = 0; languageNr < g_LanguagePrefsSize; languageNr++) {
    curInfo = &g_LanguagePrefs [languageNr];
    wxString filepattern = curInfo->filepattern;
    filepattern.Lower();
    while (!filepattern.empty()) {
        wxString cur = filepattern.BeforeFirst (';');
        if ((cur == filename) ||
            (cur == (filename.BeforeLast ('.') + _T(".*"))) ||
            (cur == (_T("*.") + filename.AfterLast ('.')))) {
            return curInfo->name;
        }
        filepattern = filepattern.AfterFirst (';');
    }
}
return wxEmptyString;
