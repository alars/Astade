//~~ bool OnInit() [CodeEditApp] ~~

wxCmdLineParser aParser(argc, argv);
aParser.AddSwitch(wxS("h"), wxS("help"), wxS("show this help"), wxCMD_LINE_OPTION_HELP);
aParser.AddOption(wxS("l"), wxS("line"), wxS("the line number to place the cursor"), wxCMD_LINE_VAL_NUMBER);
aParser.AddParam(wxS("input file"), wxCMD_LINE_VAL_STRING, wxCMD_LINE_OPTION_MANDATORY);

if (aParser.Parse() == 0)
{
    wxFileName aFile(aParser.GetParam());

    aFile.SetFullName(wxS("ModelNode.ini"));

    AdeModelElement* anElement = AdeModelElement::CreateNewElement(aFile);

    long initLine;
    if (!aParser.Found(wxS("l"), &initLine))
        initLine = -1;

    wxFileName aFileName(aParser.GetParam());
    aFileName.MakeRelativeTo();
    if (dynamic_cast<AdeOperationBase*>(anElement))
        myFrame = new CodeEditFrame(aFileName.GetFullPath(), anElement->GetLabel());
    else if (dynamic_cast<AdeClass*>(anElement))
        myFrame = new CodeEditFrame(aFileName.GetFullPath(),
                    anElement->GetLabel() + wxS("::") + aFileName.GetFullName());
    else
        myFrame = new CodeEditFrame(aFileName.GetFullPath(), aFileName.GetFullPath());

    delete anElement;

    SetTopWindow(myFrame);
    myFrame->Init(initLine);
    return true;
}
else
    return false;
