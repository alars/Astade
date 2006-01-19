wxMenu* aFileMenu = new wxMenu(0);
aFileMenu->Append(ID_SELECTMODEL,"select model directory","", wxITEM_NORMAL);

wxMenu* aCustomizeMenu = new wxMenu(0);
aCustomizeMenu->Append(ID_SETEDITORS,"set directories","", wxITEM_NORMAL);

wxMenu* aHelpMenu = new wxMenu(0);
aHelpMenu->Append(ID_MNU_HELP,"help");
aHelpMenu->Append(ID_MNU_INFO,"info");
aHelpMenu->Append(ID_MNU_ABOUT,"about");

myMenuBar.Append(aFileMenu,"Model");
myMenuBar.Append(aCustomizeMenu,"Customize");
myMenuBar.Append(aHelpMenu,"Help");
