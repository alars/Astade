static const wxCmdLineEntryDesc cmdLineDesc[] =
{
    { wxCMD_LINE_SWITCH,    wxS("h"),    wxS("help"), wxS("shows this help"), wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP},
    { wxCMD_LINE_OPTION,    wxS("T"),    wxS("type"), wxS("Has no effect, only for compatibility with mscgen."), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL},
    { wxCMD_LINE_OPTION,    wxS("i"),    wxS("infile"), wxS("Input file."), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL},
    { wxCMD_LINE_OPTION,    wxS("o"),    wxS("outfile"), wxS("The file the graphic is written to (PNG format). If this parameter is not given, the software starts in dialogue mode."), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL},
    { wxCMD_LINE_PARAM,     NULL,       NULL,       wxS("Input file"), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL},

    { wxCMD_LINE_NONE }
};

wxCmdLineParser aParser(argc, argv);
aParser.SetDesc(cmdLineDesc);

if (aParser.Parse() != 0)
    return false;

wxImage::AddHandler(new wxPNGHandler);
wxImage::AddHandler(new wxJPEGHandler);

wxString inputFile;
wxString outputFile;
if (!aParser.Found(_T("o") ,&outputFile))
{
    myFrame = new SeqFrame;
    SetTopWindow(myFrame);
    myFrame->Show(TRUE);

    if (aParser.Found(_T("i"), &inputFile))
        myFrame->Load(inputFile);
    else if (aParser.GetParamCount() > 0)
        myFrame->Load(aParser.GetParam());

    return true;
}

wxFileName aFileName(outputFile);

if (aFileName.GetExt() != _T("png") && aFileName.GetExt() != _T("jpg"))
	return false;

if (aParser.Found(_T("i"), &inputFile))
    GenerateGraphFile(inputFile, outputFile);
else if (aParser.GetParamCount() > 0)
    GenerateGraphFile(aParser.GetParam(), outputFile);

return false;
