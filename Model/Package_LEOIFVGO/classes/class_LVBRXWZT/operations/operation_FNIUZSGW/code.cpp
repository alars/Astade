static const wxCmdLineEntryDesc cmdLineDesc[] =
{
    { wxCMD_LINE_SWITCH,    _T("h"),    _T("help"), _T("shows this help"), wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP},
    { wxCMD_LINE_OPTION,    _T("T"),    _T("type"), _T("Has no effect, only for compatibility with mscgen."), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL},
    { wxCMD_LINE_OPTION,    _T("i"),    _T("infile"), _T("Input file.  If omitted or specified as '-', input will be read from stdin."), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL},
    { wxCMD_LINE_OPTION,    _T("o"),    _T("outfile"), _T("The file the graphic is written to (png formate). If this parameter is not given, the software starts in dialog mode."), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL},
    { wxCMD_LINE_PARAM,     NULL,       NULL,       _T("Input file"), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL},

    { wxCMD_LINE_NONE }
};

wxCmdLineParser aParser(argc, argv);
aParser.SetDesc(cmdLineDesc);

if (aParser.Parse() != 0)
    return false;

wxString outputFile;

if (!aParser.Found("o",&outputFile))
{
    wxImage::AddHandler(new wxPNGHandler);
    wxImage::AddHandler(new wxJPEGHandler);

    myFrame = new SeqFrame;
    SetTopWindow(myFrame);
    myFrame->Show(TRUE);

    wxString inputFile;
    if (aParser.Found("i",&inputFile))
        myFrame->Load(inputFile);
    else if (aParser.GetParamCount() > 0)
        myFrame->Load(aParser.GetParam());

    return true;
}

wxString inputFile;
aParser.Found("i",&inputFile);

wxLogMessage("Input:<%s> Output:<%s>",inputFile.c_str(),outputFile.c_str());

return false;