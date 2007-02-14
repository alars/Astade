SetIcon(wxIcon(main_xpm));
CreateStatusBar(2); // Create a statusbar with 2 fields

wxMenuBar* aMenuBar = new wxMenuBar;
wxMenu* aFileMenu = new wxMenu;
wxMenu* aHelpMenu = new wxMenu;

SetSize(-1, -1, 800, 600);

aFileMenu->Append(ID_OPEN, "&Open ...", "", wxITEM_NORMAL);
aFileMenu->Append(ID_SAVE, "&Save", "", wxITEM_NORMAL);
aFileMenu->AppendSeparator();
aFileMenu->Append(ID_PRINT, "&Print ...", "", wxITEM_NORMAL);
aFileMenu->Append(ID_PAGESETUP, "Page Set&up ...", "", wxITEM_NORMAL);
aFileMenu->AppendSeparator();
aFileMenu->Append(ID_SAVEAS, "Save &as ...", "", wxITEM_NORMAL);
aFileMenu->Append(ID_SAVEGRAPH, "Save &graphic as ...", "", wxITEM_NORMAL);
aFileMenu->Append(ID_COPYGRAPH, "&Copy graphic to clipboard", "", wxITEM_NORMAL);

aHelpMenu->Append(ID_HELP, "Text &commands ...", "", wxITEM_NORMAL);
aHelpMenu->Append(ID_ABOUT, "&About ...", "", wxITEM_NORMAL);

aMenuBar->Append(aFileMenu, "&File");
aMenuBar->Append(aHelpMenu, "&Help");
SetMenuBar(aMenuBar);

dataBase = new SeqDataBase;
noteBook = new wxNotebook(this, ID_NOTEBOOK);
graphTab = new SeqGraphTab(noteBook, dataBase);
noteBook->AddPage(graphTab, "Graph");
graphTab->theStatusBar = GetStatusBar();
textTab = new SeqTextTab(noteBook);
noteBook->AddPage(textTab, "Text");

printData = new wxPrintData;
pageSetupData = new wxPageSetupDialogData;
mySeqPrintout = new SeqPrintout(graphTab, dataBase);
