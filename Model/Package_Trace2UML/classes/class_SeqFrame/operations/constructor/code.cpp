//~~ SeqFrame() [SeqFrame] ~~
SetIcon(wxIcon(main_xpm));
CreateStatusBar(3); // Create a statusbar with 3 fields

wxMenuBar* aMenuBar = new wxMenuBar;
wxMenu* aFileMenu = new wxMenu;
wxMenu* aHelpMenu = new wxMenu;
myEditMenu = new wxMenu;

SetSize(-1, -1, 800, 600);

aFileMenu->Append(ID_OPEN, wxS("&Open ..."), wxS(""), wxITEM_NORMAL);
aFileMenu->Append(ID_SAVE, wxS("&Save"), wxS(""), wxITEM_NORMAL);
aFileMenu->AppendSeparator();
aFileMenu->Append(ID_PRINT, wxS("&Print ..."), wxS(""), wxITEM_NORMAL);
aFileMenu->Append(ID_PAGESETUP, wxS("Page Set&up ..."), wxS(""), wxITEM_NORMAL);
aFileMenu->AppendSeparator();
aFileMenu->Append(ID_SAVEAS, wxS("Save &as ..."), wxS(""), wxITEM_NORMAL);
aFileMenu->Append(ID_SAVESVG, wxS("Save &graphic as SVG"), wxS(""), wxITEM_NORMAL);
aFileMenu->Append(ID_SAVEPNG, wxS("Save &graphic as PNG"), wxS(""), wxITEM_NORMAL);
aFileMenu->Append(ID_COPYGRAPH, wxS("&Copy graphic to clipboard"), wxS(""), wxITEM_NORMAL);

aHelpMenu->Append(ID_HELP, wxS("Text &commands ..."), wxS(""), wxITEM_NORMAL);
aHelpMenu->Append(ID_ABOUT, wxS("&About ..."), wxS(""), wxITEM_NORMAL);

aMenuBar->Append(aFileMenu, wxS("&File"));
aMenuBar->Append(myEditMenu, wxS("&Edit"));
aMenuBar->Append(aHelpMenu, wxS("&Help"));
SetMenuBar(aMenuBar);

dataBase = new SeqDataBase(myEditMenu);
noteBook = new wxNotebook(this, ID_NOTEBOOK);
graphTab = new SeqGraphTab(noteBook, dataBase);
noteBook->AddPage(graphTab, wxS("Graph"));
graphTab->theStatusBar = GetStatusBar();
textTab = new SeqTextTab(noteBook);
noteBook->AddPage(textTab, wxS("Text"));

printData = new wxPrintData;
pageSetupData = new wxPageSetupDialogData;
mySeqPrintout = new SeqPrintout(graphTab, dataBase);
