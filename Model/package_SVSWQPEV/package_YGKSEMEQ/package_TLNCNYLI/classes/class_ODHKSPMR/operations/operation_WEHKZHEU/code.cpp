		aFileMenu = new wxMenu(0);
aFileMenu->Append(ID_CREATEMODEL, "&New Model", "Create new model.", wxITEM_NORMAL);
aFileMenu->Append(ID_SELECTMODEL, "&open model...", "Open a model directory.", wxITEM_NORMAL);

aFileMenu->AppendSeparator();
aFileMenu->Append(ID_EXIT, "E&xit", "Close Astade.", wxITEM_NORMAL);
aFileMenu->AppendSeparator();

AddRecentList();

wxMenu* aCustomizeMenu = new wxMenu(0);
aCustomizeMenu->Append(ID_SETEDITORS, "&set directories...", "Change user specific path settings.", wxITEM_NORMAL);
aCustomizeMenu->Append(ID_SETAPPS, "&set user-applications...", "Change user specific add-on applications.", wxITEM_NORMAL);
aCustomizeMenu->Append(ID_SETREGEX, "set &regular expressions...", "Change regular expressions for parsing the make output.", wxITEM_NORMAL);
aCustomizeMenu->Append(ID_TABWIDTH, "set &tabsize (roundtrip)", "Set the default tabsize for the roundtrip.", wxITEM_NORMAL);

wxMenu* aHelpMenu = new wxMenu(0);
aHelpMenu->Append(ID_MNU_HELP, "&help");
aHelpMenu->Append(ID_MNU_INFO, "&info");
aHelpMenu->Append(ID_MNU_ABOUT, "&about");

myMenuBar = new wxMenuBar;
myMenuBar->Append(aFileMenu, "&File");
myMenuBar->Append(aCustomizeMenu, "&Preferences");
myMenuBar->Append(aHelpMenu, "&Help");
