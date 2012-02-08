wxConfigBase* theConfig = new wxFileConfig(wxS("AstadeCodeEdit.ini"));

int x,y,w,h;
GetPosition(&x,&y);
GetSize(&w,&h);

theConfig->Write(wxS("CodeEdit/XPos"), x);
theConfig->Write(wxS("CodeEdit/YPos"), y);

theConfig->Write(wxS("CodeEdit/XSize"), w);
theConfig->Write(wxS("CodeEdit/YSize"), h);

if (myFindReplaceData)
{
    theConfig->Write(wxS("CodeEdit/FindFlags"), myFindReplaceData->GetFlags());
    theConfig->Write(wxS("CodeEdit/FindString"), myFindReplaceData->GetFindString());
}

theConfig->Flush();
delete theConfig;

delete myFindReplaceDialog;
delete myFindReplaceData;
