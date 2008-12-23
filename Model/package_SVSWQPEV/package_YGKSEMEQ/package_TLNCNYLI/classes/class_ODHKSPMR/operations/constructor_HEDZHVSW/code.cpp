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
myStatusBar = CreateStatusBar(2);
int values[] = {60,-1};
myStatusBar->SetStatusWidths(2,values);
dynamic_cast<AstadeStatusBar*>(myStatusBar)->SetTree(myTree);

wxToolBar* myToolBar = CreateToolBar();
myToolBar->AddTool(ID_TOOL_GENERATE, "Generate", AstadeIcons::GetGenerateIcon(), "generate all outdated classes");
myToolBar->AddTool(ID_TOOL_BUILD, "Build", AstadeIcons::GetLaunchBuildIcon(), "launch build process");
myConfigList = new wxChoice(myToolBar, ID_TOOL_CONFIG);
myToolBar->AddControl(myConfigList);
myBuildTargetList = new wxChoice(myToolBar, ID_TOOL_BUILDTARGET);
myToolBar->AddControl(myBuildTargetList);
myToolBar->AddTool(ID_TOOL_RUN, "Run", AstadeIcons::GetRunIcon(), "execute the target");
myRunTargetList = new wxChoice(myToolBar, ID_TOOL_RUNTARGET);
myToolBar->AddControl(myRunTargetList);
myToolBar->AddTool(ID_TOOL_FASTRUN, "FastRun", AstadeIcons::GetFastrunIcon(), "generate, build and execute the target");
myToolBar->Realize();
UpdateToolbar();

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