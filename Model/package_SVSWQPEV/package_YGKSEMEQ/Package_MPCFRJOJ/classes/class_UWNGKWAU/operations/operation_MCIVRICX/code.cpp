wxConfigBase* theConfig = new wxFileConfig("AstadeCodeEdit.ini");
int x,y,w,h;

theConfig->Read("CodeEdit/XPos",&x,-1);
theConfig->Read("CodeEdit/YPos",&y,-1);

theConfig->Read("CodeEdit/XSize",&w,-1);
theConfig->Read("CodeEdit/YSize",&h,-1);

SetSize(x,y,w,h);
delete theConfig;

Show(true);