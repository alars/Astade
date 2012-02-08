//~~ int doit(int argc, char* const* argv) [CSDgenerator] ~~
// vi: set tabstop=4:
wxConfigBase::Set(new wxFileConfig(wxS("Astade.ini")));
wxCmdLineParser CmdLineParser(argc, const_cast<char**>(argv));

CmdLineParser.AddParam(wxS("model_node"), wxCMD_LINE_VAL_STRING, wxCMD_LINE_OPTION_MANDATORY);

CmdLineParser.SetLogo(wxS("OMDgenerator: the \"Composite Structure Diagram generator\"\n" COPYRIGHT));

if (CmdLineParser.Parse() == 0 && CmdLineParser.GetParamCount() == 1)
{
	std::cout << "digraph G {" << std::endl;
    std::cout << "rankdir=LR;" << std::endl;
    std::cout << "compound=true;" << std::endl;

    std::cout << "subgraph cluster0 {" << std::endl;
    std::cout << "fontname=arial" << std::endl;
    std::cout << "fontsize=12" << std::endl;

	wxFileName base(CmdLineParser.GetParam(0));
	AdeModelElement* element = AdeModelElement::CreateNewElement(base);
    AdeClass* aClass = dynamic_cast<AdeClass*>(element);

    if (aClass)
    {
        std::cout << "label = \"" << aClass->GetName() << "\";" << std::endl;

        std::cout << nodename << "[shape=point, style=invis]" << std::endl;
        CodeCapsuledObjects(aClass);
        std::cout << "}" << std::endl;

        CodePorts(aClass);
    }

	std::cout << "}" << std::endl;

	return EXIT_SUCCESS;
}
return EXIT_FAILURE;
