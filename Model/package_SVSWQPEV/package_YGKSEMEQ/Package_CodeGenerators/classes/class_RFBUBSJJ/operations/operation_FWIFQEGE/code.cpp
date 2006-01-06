// vi: set tabstop=4:
wxConfigBase::Set(new wxFileConfig("Astade.ini"));
wxCmdLineParser CmdLineParser(argc, const_cast<char**>(argv));

CmdLineParser.AddParam("class_dir", wxCMD_LINE_VAL_STRING, wxCMD_LINE_OPTION_MANDATORY);
CmdLineParser.AddParam("target", wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL);

CmdLineParser.SetLogo("CppGenerator: the \"C++ code generator\"\n"
	"from the Astade project (astade.tigris.org)\n"
	"Copyright (C) 2005  Thomas Spitzer and Anders Larsen\n\n"
	"This program is distributed in the hope that it will be useful,\n"
	"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
	"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
	"GNU General Public License for more details.\n\n"
	"To contact the author, mail to: dev@astade.tigris.org\n");

if (CmdLineParser.Parse() == 0)
{
	wxFileName base(CmdLineParser.GetParam(0));
	base.SetFullName("ModelNode.ini");
	AdeModelElement* element = AdeModelElement::CreateNewElement(base);
	if ((element->GetType() & 0xFF00000) != ITEM_IS_CLASS)
	{
		CmdLineParser.Usage();
		return EXIT_FAILURE;
	}
	source = dynamic_cast<AdeClass*>(element);
	assert(source);
	if (CmdLineParser.GetParamCount() > 1)
		target = CmdLineParser.GetParam(1);
	else
		target = source->GetSpecFileName();
	
	return EXIT_SUCCESS;
}
return EXIT_FAILURE;
