CreateStatusBar(1); // Create a statusbar with 1 field

wxMenuBar* aMenuBar = new wxMenuBar;
wxMenu* aFileMenu = new wxMenu(0);

SetSize(-1,-1,800,600);

aFileMenu->Append(ID_OPEN,"Open","", wxITEM_NORMAL);
aFileMenu->Append(ID_SAVE,"Save","", wxITEM_NORMAL);
aFileMenu->AppendSeparator();
aFileMenu->Append(ID_SAVEAS,"Save as ...","", wxITEM_NORMAL);
aFileMenu->Append(ID_SAVEGRAPH,"Save graphic as ...","", wxITEM_NORMAL);

aMenuBar->Append(aFileMenu,"File");
SetMenuBar(aMenuBar);

dataBase = new SeqDataBase();

noteBook = new wxNotebook(this,ID_NOTEBOOK);

graphTab = new SeqGraphTab(noteBook,dataBase);
noteBook->AddPage(graphTab,"Graph");

textTab = new SeqTextTab(noteBook);
noteBook->AddPage(textTab,"Text");