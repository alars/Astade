//~~ int doit(int argc, char* const* argv) [OMDgenerator] ~~
// vi: set tabstop=4:
wxConfigBase::Set(new wxFileConfig("Astade.ini"));
wxCmdLineParser CmdLineParser(argc, const_cast<char**>(argv));

CmdLineParser.AddParam("model_node", wxCMD_LINE_VAL_STRING, wxCMD_LINE_OPTION_MANDATORY);
CmdLineParser.AddSwitch("e", "externals", "show external relations");
CmdLineParser.AddSwitch("s", "all-classes", "include scope outside of active component");
CmdLineParser.AddSwitch("p", "drawports", "draws all ports (input and output) of the classes");
CmdLineParser.AddOption("a", "attributes", "attribute display level (0..3)", wxCMD_LINE_VAL_NUMBER);
CmdLineParser.AddOption("o", "operations", "operation display level (0..3)", wxCMD_LINE_VAL_NUMBER);

CmdLineParser.SetLogo("OMDgenerator: the \"Object Model Diagram generator\"\n" COPYRIGHT);

if (CmdLineParser.Parse() == 0 && CmdLineParser.GetParamCount() == 1)
{
	long verbosity;
	if (CmdLineParser.Found("a", &verbosity))
	{
		if (verbosity < 0 || verbosity > 3)
		{
			CmdLineParser.Usage();
			return EXIT_FAILURE;
		}
		showattr = static_cast<tVisibility>(verbosity);
	}
	if (CmdLineParser.Found("o", &verbosity))
	{
		if (verbosity < 0 || verbosity > 3)
		{
			CmdLineParser.Usage();
			return EXIT_FAILURE;
		}
		showoper = static_cast<tVisibility>(verbosity);
	}
	showall = CmdLineParser.Found("s");
	showext = CmdLineParser.Found("e");
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
