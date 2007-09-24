static const wxCmdLineEntryDesc cmdLineDesc[] =
{
    { wxCMD_LINE_SWITCH,	_T("h"),	_T("help"),	_T("shows this help"), wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP },
    { wxCMD_LINE_SWITCH,	_T("l"),	_T("line"),	_T("the line number to place the cursor") },
    { wxCMD_LINE_PARAM,		NULL,	NULL,	_T("input file"), wxCMD_LINE_VAL_STRING, wxCMD_LINE_OPTION_MANDATORY },

    { wxCMD_LINE_NONE }
};

wxCmdLineParser aParser(argc, argv);
aParser.SetDesc(cmdLineDesc);

if (aParser.Parse() == 0)
{
	wxString filename;
	myFrame = new CodeEditFrame(wxGetApp().argv[1]);
	SetTopWindow(myFrame);
	myFrame->Init();
	return true;
}
else
	return false;
