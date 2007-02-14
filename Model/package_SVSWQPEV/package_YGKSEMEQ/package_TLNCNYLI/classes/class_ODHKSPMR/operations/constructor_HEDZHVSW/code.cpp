aTimer.Start(100);

myDropTarget = new AstadeDropTarget(this);
SetDropTarget(myDropTarget);
srand(static_cast<unsigned>(time(0)));

myTree =  new AstadeTree(this);
myMakeOutput = new AstadeMakeOutput(myTree);
myOmdDialog =  new AstadeOmdDialog(this);

theMakeProcess = NULL;

InitializeHelp();
InitializeMenubar();
InitializeKeyboardShortCut();
SetMenuBar(myMenuBar);
myStatusBar = CreateStatusBar();

wxConfigBase* theConfig = wxConfigBase::Get();

wxString entry;
long dummy;

theConfig->SetPath("/ExpandedNodes");
bool cont = theConfig->GetFirstEntry(entry,dummy);

while (cont)
{
    myTree->ShowNode(AdeGUIDCache::Instance()->GetCachedEntry(entry).GetFullPath());
    wxTreeItemId aID = myTree->GetSelection();
    if (!myTree->IsExpanded(aID))
    	myTree->Expand(aID);
	cont = theConfig->GetNextEntry(entry,dummy);
}

theConfig->SetPath("/");


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
