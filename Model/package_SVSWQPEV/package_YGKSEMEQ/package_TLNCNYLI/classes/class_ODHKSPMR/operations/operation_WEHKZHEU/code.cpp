myMenuBar = new wxMenuBar;
wxMenu* aCustomizeMenu = new wxMenu(0);
aCustomizeMenu->Append(ID_SETEDITORS,"set editors","", wxITEM_NORMAL);

wxMenu* aHelpMenu = new wxMenu(0);
aHelpMenu->Append(ID_MNU_HELP,"Help");
aHelpMenu->Append(ID_MNU_INFO,"Info");

myMenuBar->Append(aCustomizeMenu,"Cusomize");
myMenuBar->Append(aHelpMenu,"Help");
