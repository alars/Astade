aTimer.Start(100);

myTree =  new AstadeTree(this);
theMakeProcess = NULL;

InitializeHelp();
InitializeMenubar();
SetMenuBar(&myMenuBar);
SetStatusBar(&myStatusBar);

srand(static_cast<unsigned>(time(0)));

