wxConfigBase* theConfig = new wxFileConfig("AstadeCodeEdit.ini");

int x,y,w,h;
GetPosition(&x,&y);
GetSize(&w,&h);

theConfig->Write("CodeEdit/XPos",x);
theConfig->Write("CodeEdit/YPos",y);

theConfig->Write("CodeEdit/XSize",w);
theConfig->Write("CodeEdit/YSize",h);

if (myFindReplaceData)
{
    theConfig->Write("CodeEdit/FindFlags",myFindReplaceData->GetFlags());
    theConfig->Write("CodeEdit/FindString",myFindReplaceData->GetFindString());
}

theConfig->Flush();
delete theConfig;

delete myFindReplaceDialog;
delete myFindReplaceData;