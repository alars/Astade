//~~ bool OnInit() [SeqApplication] ~~

wxCmdLineParser aParser(argc, argv);
aParser.AddSwitch(wxS("h"), wxS("help"), wxS("shows this help"), wxCMD_LINE_OPTION_HELP);
aParser.AddOption(wxS("T"), wxS("type"), wxS("Has no effect, only for compatibility with mscgen."), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL);
aParser.AddOption(wxS("i"), wxS("infile"), wxS("Input file."), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL);
aParser.AddOption(wxS("o"), wxS("outfile"), wxS("The file the graphic is written to (PNG format). If this parameter is not given, the software starts in dialogue mode."), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL);
aParser.AddOption(wxS("d"), wxS("drawio"), wxS("The file the graphic is written to in drawio format."), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL);
aParser.AddParam(wxS("Input file"), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL);

if (aParser.Parse() != 0)
    return false;

wxImage::AddHandler(new wxPNGHandler);
wxImage::AddHandler(new wxJPEGHandler);

wxString inputFile;
wxString outputFile;
wxString drawioFile;

bool outputFound = aParser.Found(wxS("o"), &outputFile);
bool drawioFound = aParser.Found(wxS("d"), &drawioFile);

wxString aType;
if (!outputFound && !drawioFound)
{
    myFrame = new SeqFrame;
    SetTopWindow(myFrame);
    myFrame->Show(TRUE);

    if (aParser.Found(wxS("i"), &inputFile))
        myFrame->Load(inputFile);
    else if (aParser.GetParamCount() > 0)
        myFrame->Load(aParser.GetParam());

    return true;
}

if (aParser.Found(wxS("T"), &aType) && aType == wxS("ismap"))
{   
    wxTextFile aTextFile(outputFile);
    aTextFile.AddLine(wxEmptyString);
    aTextFile.Write();
    return false;
}

wxFileName aFileName(outputFile);

if (aFileName.GetExt() != wxS("png") && aFileName.GetExt() != wxS("jpg"))
	outputFile.clear();

if (aParser.Found(wxS("i"), &inputFile))
    GenerateGraphFile(inputFile, outputFile, drawioFile);
else if (aParser.GetParamCount() > 0)
    GenerateGraphFile(aParser.GetParam(), outputFile, drawioFile);
exit(0);
return false;
