//******************************************************
//** Coding is done with Astade Quick and Dirty Coder **
//** Filename: StateChartDrawer.cpp                   **
//******************************************************

//****** implementation prolog ******
#include <wx/cmdline.h>
//***********************************
#include "StateChartDrawer.h" // own header



int StateChartDrawer::doit(int argc,char* const* argv)
{
	wxCmdLineParser CmdLineParser(argc, const_cast<char**>(argv));
	CmdLineParser.AddParam("DIRNAME",wxCMD_LINE_VAL_STRING,wxCMD_LINE_OPTION_MANDATORY);
	CmdLineParser.SetLogo("\nOMDgenerator: the \"Statchart drawer\"\n"
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
		"To contact the author, mail to: author@astade.de\n\n");
	
	if (CmdLineParser.Parse() == 0)
	{
		printf("digraph G {\n");
		printf("\tnode [shape=box, fontname=arial, fontsize=12]\n");
		printf("}\n");
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
};
//****** implementation epilog ******
int main(int argc, char* const* argv)
{
	StateChartDrawer Drawer;
	return Drawer.doit(argc, argv);
}
//***********************************
