// vi: set tabstop=4:
wxCmdLineParser CmdLineParser(argc, const_cast<char**>(argv));
CmdLineParser.AddParam("model node", wxCMD_LINE_VAL_STRING, wxCMD_LINE_OPTION_MANDATORY);
CmdLineParser.AddSwitch("l", "local", "don't show external relations");
CmdLineParser.SetLogo("\nOMDgenerator: the \"Object Model Diagram generator\"\n"
	"from the Astade project (astade.tigris.org)\n"
	"Copyright (C) 2005  Thomas Spitzer and Anders Larsen\n\n"
	"This program is free software; you can redistribute it and/or modify\n"
	"it under the terms of the GNU General Public License as published by\n"
	"the Free Software Foundation; either version 2 of the License, or\n"
	"(at your option) any later version.\n\n"
	"This program is distributed in the hope that it will be useful,\n"
	"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
	"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
	"GNU General Public License for more details.\n\n"
	"You should have received a copy of the GNU General Public License\n"
	"along with this program; if not, write to the Free Software\n"
	"Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA\n\n"
	"To contact the author, mail to: dev@astade.tigris.org\n\n");

if (CmdLineParser.Parse() == 0 && CmdLineParser.GetParamCount() == 1)
{
	onlylocal = CmdLineParser.Found("l");
	std::cout << "digraph G {"
		<< std::endl;
	std::cout << "\tnode [shape=box, fontname=arial, fontsize=10]"
		<< std::endl;
	wxFileName base(CmdLineParser.GetParam(0));
	AdeModelElement element(base);
	ListNodes(1, wxEmptyString, &element);
	ListEdges(wxEmptyString, &element);
	std::cout << '}'
		<< std::endl;
	return EXIT_SUCCESS;
}       
return EXIT_FAILURE;
