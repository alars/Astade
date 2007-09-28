wxConfigBase* theConfig = new wxFileConfig("AstadeCodeEdit.ini");

int x,y,w,h;
GetPosition(&x,&y);
GetSize(&w,&h);

theConfig->Write("CodeEdit/XPos",x);
theConfig->Write("CodeEdit/YPos",y);

theConfig->Write("CodeEdit/XSize",w);
theConfig->Write("CodeEdit/YSize",h);

theConfig->Flush();
delete theConfig;

delete myFindReplaceDialog;
delete myFindReplaceData;