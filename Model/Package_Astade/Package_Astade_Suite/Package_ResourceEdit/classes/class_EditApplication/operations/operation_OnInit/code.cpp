//~~ bool OnInit() [EditApplication] ~~

static const wxCmdLineEntryDesc cmdLineDesc[] =
{
    { wxCMD_LINE_SWITCH,	wxS("h"),	wxS("help"),	wxS("shows this help"), wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP },
    { wxCMD_LINE_SWITCH,	wxS("p"),	wxS("package"),	wxS("generates a new file for a package description. The filename of the .ini file is only a 'hint' in this case") },
    { wxCMD_LINE_PARAM,		NULL,	NULL,	wxS("filename of the .ini file which shall be changed"), wxCMD_LINE_VAL_STRING, wxCMD_LINE_OPTION_MANDATORY },

    { wxCMD_LINE_NONE }
};

wxCmdLineParser aParser(argc, argv);
aParser.SetDesc(cmdLineDesc);

if (aParser.Parse() == 0)
{
	wxInitAllImageHandlers();
	myDlg = new ResourceEdit;

	wxFileConfig* theConfig = new wxFileConfig(wxEmptyString,wxEmptyString,wxGetApp().argv[1]);
	wxConfigBase::Set(theConfig);

	SetTopWindow(myDlg);
	myDlg->Show(TRUE);

	return TRUE;
}
else
	return false;
