//~~ void OnSearchEnd(wxFindDialogEvent& event) [CodeEditFrame] ~~
delete myFindReplaceData;
myFindReplaceData = 0;

myFindReplaceDialog->Destroy();
myFindReplaceDialog = 0;

searchButton->Enable();
replaceButton->Enable();
