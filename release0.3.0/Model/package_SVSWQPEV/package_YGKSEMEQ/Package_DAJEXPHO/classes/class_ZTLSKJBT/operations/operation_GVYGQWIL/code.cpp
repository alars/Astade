wxCmdLineParser CmdLineParser(argc, const_cast<char**>(argv));
CmdLineParser.AddParam("DIRNAME",wxCMD_LINE_VAL_STRING,wxCMD_LINE_OPTION_MANDATORY);
CmdLineParser.AddParam("TARGETFILE",wxCMD_LINE_VAL_STRING,wxCMD_LINE_OPTION_MANDATORY);

CmdLineParser.SetLogo("\nStatChartCoder: the \"Statchart coder\"\n"
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
	if (CmdLineParser.GetParamCount()==2)
	{
		AdeStatechart theElement(CmdLineParser.GetParam(0));

		if ((theElement.GetType()&0x7f00000)!=ITEM_IS_STATECHART)
		{
			printf("Error: only State charts please!");
			return EXIT_FAILURE;
		}

        wxFileName theFileName = CmdLineParser.GetParam(1);
	    theFileName.SetExt("cpp");
	    implementationFile = fopen(theFileName.GetFullPath().c_str(),"w");

	    fprintf(implementationFile,"//******************************************************\n");
	    fprintf(implementationFile,"//** Coding is done with Astade Statechart coder      **\n");
	    fprintf(implementationFile,"//** Filename: %-39s**\n",theFileName.GetFullName().c_str());
	    fprintf(implementationFile,"//******************************************************\n\n");

	    theFileName.SetExt("h");
	    specificationFile = fopen(theFileName.GetFullPath().c_str(),"w");

	    fprintf(specificationFile,"//******************************************************\n");
	    fprintf(specificationFile,"//** Coding is done with Astade Statechart coder      **\n");
	    fprintf(specificationFile,"//** Filename: %-39s**\n",theFileName.GetFullName().c_str());
	    fprintf(specificationFile,"//******************************************************\n\n");

		fprintf(specificationFile,"//!\\file %s\n\n",theFileName.GetFullName().c_str());

		CodeStatechart(theElement);

	    fclose(implementationFile);
	    fclose(specificationFile);

		return EXIT_SUCCESS;
	}
	else
		return EXIT_FAILURE;
}

return EXIT_FAILURE;
