wxMenu* aRevisionControlMenu = new wxMenu(0);
aRevisionControlMenu->AppendRadioItem(ID_SELECTNONE,"none");
aRevisionControlMenu->AppendRadioItem(ID_SELECTSVN,"SVN");
aRevisionControlMenu->AppendRadioItem(ID_SELECTCVS,"CVS");
aRevisionControlMenu->Enable(ID_SELECTCVS,false);

wxMenu* aFileMenu = new wxMenu(0);
aFileMenu->Append(ID_SELECTMODEL,"select model directory","", wxITEM_NORMAL);

wxMenu* aCustomizeMenu = new wxMenu(0);
aCustomizeMenu->Append(ID_SETEDITORS,"set directories","", wxITEM_NORMAL);
aCustomizeMenu->Append(-1,"select revision control",aRevisionControlMenu);

wxMenu* aHelpMenu = new wxMenu(0);
aHelpMenu->Append(ID_MNU_HELP,"help");
aHelpMenu->Append(ID_MNU_INFO,"info");
aHelpMenu->Append(ID_MNU_ABOUT,"about");

myMenuBar.Append(aFileMenu,"Model");
myMenuBar.Append(aCustomizeMenu,"Customize");
myMenuBar.Append(aHelpMenu,"Help");
