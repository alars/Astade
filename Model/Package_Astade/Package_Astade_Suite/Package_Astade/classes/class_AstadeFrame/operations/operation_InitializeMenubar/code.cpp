//~~ void InitializeMenubar() [AstadeFrame] ~~

aFileMenu = new wxMenu(0);
aFileMenu->Append(ID_CREATEMODEL, wxS("&New Model\tCtrl+N"), wxS("Create a new model."), wxITEM_NORMAL);
aFileMenu->Append(ID_SELECTMODEL, wxS("&Open Model\tCtrl+O"), wxS("Open a model directory."), wxITEM_NORMAL);

aFileMenu->AppendSeparator();
aFileMenu->Append(ID_EXIT, wxS("E&xit\tAlt+F4"), wxS("Close Astade."), wxITEM_NORMAL);
aFileMenu->AppendSeparator();

AddRecentList();

wxMenu* aToolMenu = new wxMenu(0);
aToolMenu->Append(ID_TOOL_GENERATE, wxS("&Generate\tF5"), wxS("Generate only classes with changes."), wxITEM_NORMAL);
aToolMenu->Append(ID_REGENERATE, wxS("Regenerate\tShift+F5"), wxS("Regenerate all classes"), wxITEM_NORMAL);
aToolMenu->Append(ID_TOOL_BUILD, wxS("&Build\tF6"), wxS("Executes make for the selected standard configuration."), wxITEM_NORMAL);
aToolMenu->Append(ID_TOOL_FASTBUILD, wxS("Generate/Build\tShift+F6"), wxS("Generates and executes make for the selected standard configuration."), wxITEM_NORMAL);
aToolMenu->Append(ID_TOOL_RUN, wxS("&Run\tF7"), wxS("Executes make for the selected configurations run target."), wxITEM_NORMAL);
aToolMenu->Append(ID_TOOL_FASTRUN, wxS("Generate/Run\tShift+F7"), wxS("Generate, build and execute."), wxITEM_NORMAL);
aToolMenu->Append(ID_SEARCH, wxS("&Search\tCtrl+F"), wxS("Opens the search dialog."), wxITEM_NORMAL);
aToolMenu->Append(ID_ALL_TRACE_OFF, wxS("Switch all tracing off"), wxS("Resets the tracing flag for all classes in the Model."), wxITEM_NORMAL);

wxMenu* aCustomizeMenu = new wxMenu(0);
aCustomizeMenu->Append(ID_SETEDITORS, wxS("Set &Directories..."), wxS("Change user specific path settings."), wxITEM_NORMAL);
aCustomizeMenu->Append(ID_SETAPPS, wxS("Set &User-Applications..."), wxS("Change user specific add-on applications."), wxITEM_NORMAL);
aCustomizeMenu->Append(ID_SETREGEX, wxS("Set &Regular Expressions..."), wxS("Change regular expressions for parsing the make output."), wxITEM_NORMAL);
aCustomizeMenu->Append(ID_TABWIDTH, wxS("Set &Tabsize (Roundtrip)"), wxS("Set the default tabsize for the roundtrip."), wxITEM_NORMAL);

wxMenu* aHelpMenu = new wxMenu(0);
aHelpMenu->Append(ID_MNU_HELP, wxS("&Help\tF1"));
aHelpMenu->Append(ID_MNU_ABOUT, wxS("&About"));

myMenuBar = new wxMenuBar;
myMenuBar->Append(aFileMenu, wxS("&File"));
myMenuBar->Append(aToolMenu, wxS("&Tools"));
myMenuBar->Append(aCustomizeMenu, wxS("&Preferences"));
myMenuBar->Append(aHelpMenu, wxS("&Help"));
