aFileMenu = new wxMenu(0);
aFileMenu->Append(ID_CREATEMODEL, "&New Model\tCtrl+N", "Create a new model.", wxITEM_NORMAL);
aFileMenu->Append(ID_SELECTMODEL, "&Open Model\tCtrl+O", "Open a model directory.", wxITEM_NORMAL);

aFileMenu->AppendSeparator();
aFileMenu->Append(ID_EXIT, "E&xit\tAlt+F4", "Close Astade.", wxITEM_NORMAL);
aFileMenu->AppendSeparator();

AddRecentList();

wxMenu* aToolMenu = new wxMenu(0);
aToolMenu->Append(ID_TOOL_GENERATE, "&Generate\tF5", "Generate only classes with changes.", wxITEM_NORMAL);
aToolMenu->Append(ID_REGENERATE, "Regenerate\tShift+F5", "Regenerate all classes", wxITEM_NORMAL);
aToolMenu->Append(ID_TOOL_BUILD, "&Build\tF6", "Executes make for the selected standard configuration.", wxITEM_NORMAL);
aToolMenu->Append(ID_TOOL_FASTBUILD, "Generate/Build\tShift+F6", "Generates and executes make for the selected standard configuration.", wxITEM_NORMAL);
aToolMenu->Append(ID_TOOL_RUN, "&Run\tF7", "Executes make for the selected configurations run target.", wxITEM_NORMAL);
aToolMenu->Append(ID_TOOL_FASTRUN, "Generate/Run\tShift+F7", "Generate, build and execute.", wxITEM_NORMAL);
aToolMenu->Append(ID_SEARCH, "&Search\tCtrl+F", "Opens the search dialog.", wxITEM_NORMAL);
aToolMenu->Append(ID_ALL_TRACE_OFF, "Switch all tracing off", "Resets the tracing flag for all classes in the Model.", wxITEM_NORMAL);

wxMenu* aCustomizeMenu = new wxMenu(0);
aCustomizeMenu->Append(ID_SETEDITORS, "Set &Directories...", "Change user specific path settings.", wxITEM_NORMAL);
aCustomizeMenu->Append(ID_SETAPPS, "Set &User-Applications...", "Change user specific add-on applications.", wxITEM_NORMAL);
aCustomizeMenu->Append(ID_SETREGEX, "Set &Regular Expressions...", "Change regular expressions for parsing the make output.", wxITEM_NORMAL);
aCustomizeMenu->Append(ID_TABWIDTH, "Set &Tabsize (Roundtrip)", "Set the default tabsize for the roundtrip.", wxITEM_NORMAL);

wxMenu* aHelpMenu = new wxMenu(0);
aHelpMenu->Append(ID_MNU_HELP, "&Help\tF1");
aHelpMenu->Append(ID_MNU_ABOUT, "&About");

myMenuBar = new wxMenuBar;
myMenuBar->Append(aFileMenu, "&File");
myMenuBar->Append(aToolMenu, "&Tools");
myMenuBar->Append(aCustomizeMenu, "&Preferences");
myMenuBar->Append(aHelpMenu, "&Help");
