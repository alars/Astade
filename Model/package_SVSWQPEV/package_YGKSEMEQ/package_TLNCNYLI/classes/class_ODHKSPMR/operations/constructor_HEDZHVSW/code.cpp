InitializeHelp();
InitializeMenubar();
SetMenuBar(&myMenuBar);
SetStatusBar(&myStatusBar);

srand(static_cast<unsigned>(time(0)));
myTree =  new wxTreeCtrl(this, ID_WXTREECTRL, wxPoint(0,0),GetClientSize(), wxTR_HAS_BUTTONS|wxTR_EDIT_LABELS);


