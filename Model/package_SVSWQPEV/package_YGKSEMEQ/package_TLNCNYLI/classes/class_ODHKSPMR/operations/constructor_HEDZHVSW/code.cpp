InitializeHelp();
InitializeMenubar();

srand(static_cast<unsigned>(time(0)));
myStatusBar =  new wxStatusBar(this, ID_WXSTATUSBAR );
myTree =  new wxTreeCtrl(this, ID_WXTREECTRL, wxPoint(0,0),GetClientSize(), wxTR_HAS_BUTTONS|wxTR_EDIT_LABELS);

this->SetStatusBar(myStatusBar);
this->SetMenuBar(myMenuBar);
