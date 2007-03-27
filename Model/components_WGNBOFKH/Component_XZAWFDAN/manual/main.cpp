#include <wx/app.h>
#include <wx/cmdline.h>
#include <AdeDefines.h>

int main(int argc, char** argv)
{
	if (wxInitialize())
	{
		static const wxCmdLineEntryDesc cmdLineDesc[] =
		{
		    { wxCMD_LINE_SWITCH, "h", "help",    		"display this help screen"	, wxCMD_LINE_VAL_NONE  , wxCMD_LINE_OPTION_HELP },
		    { wxCMD_LINE_OPTION, "c", "component",		"The path or \"modelnode.ini\" of the component. The \"active\" component from \"Astade.ini\" is used as default." , wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
		    { wxCMD_LINE_OPTION, "d", "output-dir",		"Specify a target directory for the generated files. The components \"auto\" directory is used as default." , wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
		    { wxCMD_LINE_OPTION, "C", "coder",			"Specify the coder to use for codings. The coder specified in \"Astade.ini\" is used as default." , wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
		    { wxCMD_LINE_OPTION, "S", "statechart-coder","Specify the statechart coder to use for codings. The statechart coder specified in \"Astade.ini\" is used as default." , wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
		    { wxCMD_LINE_SWITCH, "X", "clean",			"All files (expect \"ModelNode.ini\") in the output directory are deleted, before the coding starts."},
		    { wxCMD_LINE_SWITCH, "q", "quiet",			"Don't show any success and progress messages."},
		    { wxCMD_LINE_NONE }
		};

		wxCmdLineParser aCmdLineParser(argc,argv);
		aCmdLineParser.SetDesc(cmdLineDesc);
		aCmdLineParser.SetLogo("\nAstadeGenerate: the \"command line component generator\"\n" COPYRIGHT);

		if (aCmdLineParser.Parse()!=0)
			return EXIT_FAILURE;

		wxUninitialize();
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
