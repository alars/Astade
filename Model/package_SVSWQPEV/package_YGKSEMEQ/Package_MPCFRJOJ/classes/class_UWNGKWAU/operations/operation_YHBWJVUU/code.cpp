searchButton->Disable();
replaceButton->Disable();

int style = 0;

if (event.GetId() == REPLACE)
    style = wxFR_REPLACEDIALOG;

myFindReplaceData = new wxFindReplaceData();
myFindReplaceDialog = new wxFindReplaceDialog(this,
                        myFindReplaceData, myTitle, style);

myFindReplaceDialog->Show();