#if !defined(wxS)
#  define wxS(x) wxT(x)
#else
#  undef wxS
#  define wxS(x) x
#endif

static const wxCmdLineEntryDesc cmdLineDesc[] =
{
    { wxCMD_LINE_SWITCH, wxS("h"), wxS("help"), wxS("shows this help"), wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP },
    { wxCMD_LINE_OPTION, wxS("l"), wxS("line"), wxS("the line number to place the cursor"), wxCMD_LINE_VAL_NUMBER },
    { wxCMD_LINE_PARAM,  NULL,     NULL,        wxS("input file"), wxCMD_LINE_VAL_STRING, wxCMD_LINE_OPTION_MANDATORY },

    { wxCMD_LINE_NONE }
};

wxCmdLineParser aParser(argc, argv);
aParser.SetDesc(cmdLineDesc);

if (aParser.Parse() == 0)
{
    wxFileName aFile(aParser.GetParam());

    aFile.SetFullName("ModelNode.ini");

    AdeModelElement* aElement = AdeModelElement::CreateNewElement(aFile);

    long initLine;
    if (!aParser.Found("l",&initLine))
        initLine = -1;

    wxFileName aFileName(aParser.GetParam());
    aFileName.MakeRelativeTo();
    if (dynamic_cast<AdeOperationBase*>(aElement))
        myFrame = new CodeEditFrame(aFileName.GetFullPath(), aElement->GetLabel());
    else
    if (dynamic_cast<AdeClass*>(aElement))
        myFrame = new CodeEditFrame(aFileName.GetFullPath(), 
                    aElement->GetLabel() + "::" + aFileName.GetFullName());
    else
        myFrame = new CodeEditFrame(aFileName.GetFullPath(), aFileName.GetFullPath());
    
    delete aElement;
    
    SetTopWindow(myFrame);
    myFrame->Init(initLine);
    return true;
}
else
    return false;
