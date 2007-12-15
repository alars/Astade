SetIcon(wxIcon(main_xpm));
CreateStatusBar(2); // Create a statusbar with 2 fields

wxMenuBar* aMenuBar = new wxMenuBar;
wxMenu* aFileMenu = new wxMenu;
wxMenu* aHelpMenu = new wxMenu;
myEditMenu = new wxMenu;

SetSize(-1, -1, 800, 600);

aFileMenu->Append(ID_OPEN, _T("&Open ..."), _T(""), wxITEM_NORMAL);
aFileMenu->Append(ID_SAVE, _T("&Save"), _T(""), wxITEM_NORMAL);
aFileMenu->AppendSeparator();
aFileMenu->Append(ID_PRINT, _T("&Print ..."), _T(""), wxITEM_NORMAL);
aFileMenu->Append(ID_PAGESETUP, _T("Page Set&up ..."), _T(""), wxITEM_NORMAL);
aFileMenu->AppendSeparator();
aFileMenu->Append(ID_SAVEAS, _T("Save &as ..."), _T(""), wxITEM_NORMAL);
aFileMenu->Append(ID_SAVEGRAPH, _T("Save &graphic as ..."), _T(""), wxITEM_NORMAL);
aFileMenu->Append(ID_COPYGRAPH, _T("&Copy graphic to clipboard"), _T(""), wxITEM_NORMAL);

aHelpMenu->Append(ID_HELP, _T("Text &commands ..."), _T(""), wxITEM_NORMAL);
aHelpMenu->Append(ID_ABOUT, _T("&About ..."), _T(""), wxITEM_NORMAL);

aMenuBar->Append(aFileMenu, _T("&File"));
aMenuBar->Append(myEditMenu, _T("&Edit"));
aMenuBar->Append(aHelpMenu, _T("&Help"));
SetMenuBar(aMenuBar);

dataBase = new SeqDataBase(myEditMenu);
noteBook = new wxNotebook(this, ID_NOTEBOOK);
graphTab = new SeqGraphTab(noteBook, dataBase);
noteBook->AddPage(graphTab, _T("Graph"));
graphTab->theStatusBar = GetStatusBar();
textTab = new SeqTextTab(noteBook);
noteBook->AddPage(textTab, _T("Text"));

printData = new wxPrintData;
pageSetupData = new wxPageSetupDialogData;
mySeqPrintout = new SeqPrintout(graphTab, dataBase);
