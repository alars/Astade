searchButton->Disable();

myFindReplaceData = new wxFindReplaceData();
myFindReplaceDialog = new wxFindReplaceDialog(this,
                        myFindReplaceData, myTitle,
                        wxFR_REPLACEDIALOG | wxFR_NOUPDOWN);

myFindReplaceDialog->Show();