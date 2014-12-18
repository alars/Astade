//~~ SeqFrame() [SeqFrame] ~~

wxString message = wxS( \
"	;	lines starting with ';' are comments. They are not drawn.\n" \
"	#	lines starting with '#' are visible comments. They are drawn with a horizontal line.\n" \
"	!	this is used to notify the existence of an object (the creation is not in the scope of the trace).\n" \
"		This is automatically inserted when you use an object name not mentioned before.\n" \
"	(!)	this is used to notify an object creation.\n" \
"	(X)	this is used to notify an object deletion.\n" \
"	>--	this is used to notify an asynchronous message send.\n" \
"	-->	this is used to notify an asynchronous message receive.\n" \
"	>->	this is a shortcut when typing traces by hand.\n" \
"		Creates both an asynchronous message send and a corresponding message receive.\n" \
"	==>	this is used to notify a synchronous function call.\n" \
"		If you leave out the caller (type \"???\") it will be replaced.\n"\
"	<==	this is used to notify a synchronous function return.\n" \
"		If you leave out the caller (type \"???\") it will be replaced.\n"\
"		If you leave out the called (type \"???\") it will be replaced.\n"\
"	ret(#)	is an alternative way to notify a synchronous function return.\n"\
"		# has to be the event number of the corresponding synchronous fuction call.\n"\
"		you may even write \"ret\" only, the corresponding call is searched.\n"\
"	>>>	this is used to notify a state change.\n" \
"	note:	this is used to add a \"note\" to an object.\n" \
"	...	a line with only 3 dots is drawn as an \"interrupton\".\n"\
"	[...]	everything set into square brackets is treated as user data.\n" \
"		It stays in the trace line without having any effect on the graphics.\n" \
"		You can use it for timestamps or remarks.\n"\
"	{...}	everything in curly bracket is treated as thread ID (when replacing \"???\")\n\n" \
"	for call and return there is another shortcut: you can write \">\" and \"<\".\n" \
"	for create and destroy there is a shortcut: you can write \"+\" and \"-\".\n\n" \
"	 If you work with Qt, you might want to instrument signal/slot connections. Than you have\n" \
"	to instrument three positions:\n" \
"		1. At the position you connect a signal to a slot, write: \"%ptr1 class1 signal ptr2 class2 slot\"\n" \
"		2. At the position you emit you write: \"}ptr1 signal\"\n" \
"		3. In your slot you write: \"{ptr2 slot\"\n\n" \
"	Trace2UML builds up a connection database and translates the emit and slot calls\n" \
"	in asynchronious events.");

helpDialog = new wxDialog(this, -1, wxS("Trace2UML Commands"), wxDefaultPosition, wxDefaultSize, wxRESIZE_BORDER | wxDEFAULT_DIALOG_STYLE);
new wxTextCtrl(helpDialog, -1, message, wxDefaultPosition,wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
helpDialog->SetSize(-1, -1, 680, 650);
helpDialog->Center();


SetIcon(wxIcon(main_xpm));
CreateStatusBar(3); // Create a statusbar with 3 fields

wxMenuBar* aMenuBar = new wxMenuBar;
wxMenu* aFileMenu = new wxMenu;
wxMenu* aHelpMenu = new wxMenu;
myEditMenu = new wxMenu;

SetSize(-1, -1, 800, 600);

aFileMenu->Append(ID_OPEN, wxS("&Open ..."), wxEmptyString, wxITEM_NORMAL);
aFileMenu->Append(ID_SAVE, wxS("&Save"), wxEmptyString, wxITEM_NORMAL);
aFileMenu->AppendSeparator();
aFileMenu->Append(ID_RELOAD, wxS("&Reload"), wxEmptyString, wxITEM_NORMAL);
aFileMenu->AppendSeparator();
aFileMenu->Append(ID_PRINT, wxS("&Print ..."), wxEmptyString, wxITEM_NORMAL);
aFileMenu->Append(ID_PAGESETUP, wxS("Page Set&up ..."), wxEmptyString, wxITEM_NORMAL);
aFileMenu->AppendSeparator();
aFileMenu->Append(ID_SAVEAS, wxS("Save &as ..."), wxEmptyString, wxITEM_NORMAL);
if (CAIRO_HAS_PDF_SURFACE)
    aFileMenu->Append(ID_SAVEPDF, wxS("Save &graphic as PDF"), wxEmptyString, wxITEM_NORMAL);
aFileMenu->Append(ID_SAVEPNG, wxS("Save &graphic as PNG"), wxEmptyString, wxITEM_NORMAL);
if (CAIRO_HAS_SVG_SURFACE)
    aFileMenu->Append(ID_SAVESVG, wxS("Save &graphic as SVG"), wxEmptyString, wxITEM_NORMAL);
aFileMenu->Append(ID_COPYGRAPH, wxS("&Copy graphic to clipboard"), wxEmptyString, wxITEM_NORMAL);

aHelpMenu->Append(ID_HELP, wxS("Text &commands ..."), wxEmptyString, wxITEM_NORMAL);
aHelpMenu->Append(ID_ABOUT, wxS("&About ..."), wxEmptyString, wxITEM_NORMAL);

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
