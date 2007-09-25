wxConfigBase* theConfig = new wxFileConfig("AstadeCodeEdit.ini");
int x,y,w,h;

theConfig->Read("CodeEdit/XPos",&x,-1);
theConfig->Read("CodeEdit/YPos",&y,-1);

theConfig->Read("CodeEdit/XSize",&w,-1);
theConfig->Read("CodeEdit/YSize",&h,-1);

delete theConfig;

Show(true);
SetSize(x,y,w,h);

myEditControl->LoadFile(myFileName);

long pos = myEditControl->XYToPosition(0,initialLine-1);

myEditControl->SetInsertionPoint(pos);
myEditControl->ShowPosition(pos);
