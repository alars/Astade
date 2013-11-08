//~~ int doit(int argc, char* const* argv) [OMDgenerator] ~~

wxConfigBase::Set(new wxFileConfig(wxS("Astade.ini")));
wxCmdLineParser CmdLineParser(argc, const_cast<char**>(argv));

CmdLineParser.AddParam(wxS("model_node"), wxCMD_LINE_VAL_STRING, wxCMD_LINE_OPTION_MANDATORY);
CmdLineParser.AddSwitch(wxS("e"), wxS("externals"), wxS("show external relations"));
CmdLineParser.AddSwitch(wxS("s"), wxS("all-classes"), wxS("include scope outside of active component"));
CmdLineParser.AddOption(wxS("c"), wxS("component"), wxS("specify the component to draw (set as active component)"), wxCMD_LINE_VAL_STRING);
CmdLineParser.AddSwitch(wxS("p"), wxS("drawports"), wxS("draws all ports (input and output) of the classes"));
CmdLineParser.AddOption(wxS("a"), wxS("attributes"), wxS("attribute display level (0..3)"), wxCMD_LINE_VAL_NUMBER);
CmdLineParser.AddOption(wxS("o"), wxS("operations"), wxS("operation display level (0..3)"), wxCMD_LINE_VAL_NUMBER);

CmdLineParser.SetLogo(wxS("OMDgenerator: the \"Object Model Diagram generator\"\n" COPYRIGHT));

if (CmdLineParser.Parse() == 0 && CmdLineParser.GetParamCount() == 1)
{
	wxString component;
    if (CmdLineParser.Found(wxS("c"), &component))
	{
        wxFileName aFilename(component);
        aFilename.MakeAbsolute();
        wxConfigBase::Get()->Write(wxS("TreeView/ActiveComponent"),aFilename.GetFullPath());
        wxConfigBase::Get()->Flush();
	}

	long verbosity;
	if (CmdLineParser.Found(wxS("a"), &verbosity))
	{
		if (verbosity < 0 || verbosity > 3)
		{
			CmdLineParser.Usage();
			return EXIT_FAILURE;
		}
		showattr = static_cast<tVisibility>(verbosity);
	}
	if (CmdLineParser.Found(wxS("o"), &verbosity))
	{
		if (verbosity < 0 || verbosity > 3)
		{
			CmdLineParser.Usage();
			return EXIT_FAILURE;
		}
		showoper = static_cast<tVisibility>(verbosity);
	}
	showall = CmdLineParser.Found(wxS("s"));
	showext = CmdLineParser.Found(wxS("e"));
	showports = CmdLineParser.Found(wxS("p"));
	std::cout << "digraph G {"
		<< std::endl;
	std::cout << "\tnode [shape=box, fontname=arial, fontsize=10]"
		<< std::endl;
	wxFileName base(CmdLineParser.GetParam(0));
	AdeModelElement* element = AdeModelElement::CreateNewElement(base);
	ListNodes(1, wxEmptyString, element);
	ListEdges(wxEmptyString, element);
	std::cout << '}'
		<< std::endl;
	return EXIT_SUCCESS;
}
return EXIT_FAILURE;
