SetIcon(wxIcon(Astade_xpm));
aTimer.Start(100);

myDropTarget = new AstadeDropTarget(this);
SetDropTarget(myDropTarget);

srand(static_cast<unsigned>(time(0)));	// Flawfinder: Ignore

myTree =  new AstadeTree(this);
AstadeTreeItemBase::SetOurTree(*myTree);

myMakeOutput = new AstadeMakeOutput(myTree);
myOmdDialog =  new AstadeOmdDialog(this);

wxConfigBase* theConfig = wxConfigBase::Get();

myTree->LoadSubnodes(myTree->GetRootItem());
myTree->Expand(myTree->GetRootItem());
myTree->LoadExpansion(myTree->GetRootItem());
theConfig->DeleteGroup("ExpandedNodes");
theConfig->Flush();

theMakeProcess = NULL;

InitializeHelp();
InitializeMenubar();
InitializeKeyboardShortCut();
SetMenuBar(myMenuBar);
myStatusBar = CreateStatusBar();
myStatusBar->SetEventHandler(this);

int x,y,w,h;

theConfig->Read("Treeview/XPos",&x,-1);
theConfig->Read("Treeview/YPos",&y,-1);

theConfig->Read("Treeview/XSize",&w,-1);
theConfig->Read("Treeview/YSize",&h,-1);

SetSize(x,y,w,h);

theConfig->Read("MakeOutput/XPos",&x,-1);
theConfig->Read("MakeOutput/YPos",&y,-1);

theConfig->Read("MakeOutput/XSize",&w,-1);
theConfig->Read("MakeOutput/YSize",&h,-1);

myMakeOutput->SetSize(x,y,w,h);
myMakeOutput->SetIcon(wxIcon(Astade_xpm));
