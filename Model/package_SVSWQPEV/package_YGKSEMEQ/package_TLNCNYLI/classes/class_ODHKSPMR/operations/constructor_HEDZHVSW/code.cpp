aTimer.Start(100);

myTree =  new AstadeTree(this);
theMakeProcess = NULL;

InitializeHelp();
InitializeMenubar();
SetMenuBar(&myMenuBar);
SetStatusBar(&myStatusBar);

srand(static_cast<unsigned>(time(0)));

wxConfigBase* theConfig = wxConfigBase::Get();
int x,y,w,h;

theConfig->Read("Treeview/XPos",&x,-1);
theConfig->Read("Treeview/YPos",&y,-1);

theConfig->Read("Treeview/XSize",&w,-1);
theConfig->Read("Treeview/YSize",&h,-1);

SetSize(x,y,w,h);