aTimer.Start(100);

myTree =  new AstadeTree(this);
myMakeOutput = new AstadeMakeOutput(myTree);
myOmdDialog =  new AstadeOmdDialog(this);

theMakeProcess = NULL;

InitializeHelp();
InitializeMenubar();
SetMenuBar(myMenuBar);
myStatusBar = CreateStatusBar();

srand(static_cast<unsigned>(time(0)));

wxConfigBase* theConfig = wxConfigBase::Get();
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

//keyboard shortcut
wxAcceleratorEntry entries[4];
  entries[0].Set(wxACCEL_CTRL,  (int) 'C',     ID_COPY);
  entries[1].Set(wxACCEL_CTRL,  (int) 'V',     ID_PASTE);
  entries[2].Set(wxACCEL_CTRL, (int) 'X',     ID_CUT);
  entries[3].Set(wxACCEL_NORMAL,  WXK_DELETE,  ID_DELETE);
  wxAcceleratorTable accel(4, entries);
  this->SetAcceleratorTable(accel);