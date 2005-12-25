CreateStatusBar(1); // Create a statusbar with 1 field

wxMenuBar* aMenuBar = new wxMenuBar;
wxMenu* aFileMenu = new wxMenu(0);

aFileMenu->Append(ID_OPEN,"Open","", wxITEM_NORMAL);
aFileMenu->Append(-1,"Save","", wxITEM_NORMAL);
aFileMenu->AppendSeparator();
aFileMenu->Append(-1,"Save as ...","", wxITEM_NORMAL);
aFileMenu->Append(-1,"Save graphic as ...","", wxITEM_NORMAL);
aFileMenu->AppendSeparator();
aFileMenu->Append(-1,"Exit","", wxITEM_NORMAL);


aMenuBar->Append(aFileMenu,"File");
SetMenuBar(aMenuBar);

dataBase = new SeqDataBase();

wxNotebook* aNoteBook = new wxNotebook(this,-1);
aNoteBook->AddPage(new SeqGraphTab(aNoteBook,dataBase),"Graph");
aNoteBook->AddPage(new SeqTextTab(aNoteBook),"Text");
aNoteBook->AddPage(new SeqFilterTab(aNoteBook),"Filter");
