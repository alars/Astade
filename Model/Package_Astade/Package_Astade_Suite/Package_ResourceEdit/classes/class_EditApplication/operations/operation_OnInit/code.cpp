//~~ bool OnInit() [EditApplication] ~~

wxCmdLineParser aParser(argc, argv);
aParser.AddSwitch(wxS("h"),	wxS("help"), wxS("shows this help"), wxCMD_LINE_OPTION_HELP);
aParser.AddSwitch(wxS("p"),	wxS("package"),	wxS("generates a new file for a package description. The filename of the .ini file is only a 'hint' in this case"));
aParser.AddParam(wxS("filename of the .ini file which shall be changed"), wxCMD_LINE_VAL_STRING, wxCMD_LINE_OPTION_MANDATORY);

if (aParser.Parse() == 0)
{
	wxInitAllImageHandlers();
	myDlg = new ResourceEdit;

	wxFileConfig* theConfig = new wxFileConfig(wxEmptyString, wxEmptyString, wxGetApp().argv[1]);
	wxConfigBase::Set(theConfig);

	SetTopWindow(myDlg);
	myDlg->Show(true);

	return true;
}
else
	return false;
