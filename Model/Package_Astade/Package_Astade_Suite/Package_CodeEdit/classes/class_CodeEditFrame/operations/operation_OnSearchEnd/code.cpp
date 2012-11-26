//~~ void OnSearchEnd(wxFindDialogEvent& event) [CodeEditFrame] ~~

if (myFindReplaceData != 0)
{
    wxConfigBase* theConfig = new wxFileConfig(wxS("AstadeCodeEdit.ini"));
    theConfig->Write(wxS("CodeEdit/FindFlags"), myFindReplaceData->GetFlags());
    theConfig->Write(wxS("CodeEdit/FindString"), myFindReplaceData->GetFindString());
    delete myFindReplaceData;
    myFindReplaceData = 0;
    delete theConfig;
}

myFindReplaceDialog->Destroy();
myFindReplaceDialog = 0;

searchButton->Enable();
replaceButton->Enable();
