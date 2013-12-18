//~~ int doIt(int argc, char** argv) [CMain] ~~
if (wxInitialize())
{
    wxCmdLineParser aCmdLineParser(argc, argv);
    aCmdLineParser.SetLogo(wxS("\ndraw2dot\n"));
    aCmdLineParser.AddSwitch(wxS("h"), wxS("help"), wxS("display this help screen"), wxCMD_LINE_OPTION_HELP);
    aCmdLineParser.AddParam(wxS("Input file"), wxCMD_LINE_VAL_STRING);

    if (aCmdLineParser.Parse() != 0)
    {
        wxUninitialize();
        return EXIT_FAILURE;
    }

    m_Filename = aCmdLineParser.GetParam();
    if (!wxFileName::FileExists(m_Filename))
    {
        std::cerr << "error: " << m_Filename.utf8_str() << "not found"<< std::endl;
        return EXIT_FAILURE;
    }
    
    generateDot();

    wxUninitialize();

    return EXIT_SUCCESS;
}
return EXIT_FAILURE;
