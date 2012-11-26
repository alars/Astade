//~~ void OnSearch(wxCommandEvent& event) [CodeEditFrame] ~~
if (!searchButton->IsEnabled())
    return;

searchButton->Disable();
replaceButton->Disable();

int style = 0;

if (event.GetId() == REPLACE)
    style = wxFR_REPLACEDIALOG;

wxConfigBase* theConfig = new wxFileConfig(wxS("AstadeCodeEdit.ini"));

int flags;
wxString aString;

theConfig->Read(wxS("CodeEdit/FindFlags"), &flags, 0);
theConfig->Read(wxS("CodeEdit/FindString"), &aString, wxEmptyString);

myFindReplaceData = new wxFindReplaceData(flags);

myFindReplaceData->SetFindString(aString);

myFindReplaceDialog = new wxFindReplaceDialog(this,
                        myFindReplaceData, myTitle, style);

delete theConfig;

myFindReplaceDialog->Show();
