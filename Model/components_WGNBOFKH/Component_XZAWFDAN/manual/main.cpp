#include <wx/app.h>
#include <wx/cmdline.h>
#include <wx/fileconf.h>
#include <wx/dir.h>
#include <AdeDefines.h>
#include <AdeModelElement.h>
#include <AdeComponent.h>


int main(int argc, char** argv)
{
	if (wxInitialize())
	{
		static const wxCmdLineEntryDesc cmdLineDesc[] =
		{
		    { wxCMD_LINE_SWITCH, "h", "help",    		"display this help screen"	, wxCMD_LINE_VAL_NONE  , wxCMD_LINE_OPTION_HELP },
		    { wxCMD_LINE_OPTION, "c", "component",		"The path or \"ModelNode.ini\" of the component. The \"active\" component from \"Astade.ini\" is used as default." , wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
		    { wxCMD_LINE_OPTION, "d", "output-dir",		"Specify a target directory for the generated files. The components \"auto\" directory is used as default." , wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
		    { wxCMD_LINE_OPTION, "C", "coder",			"Specify the coder to use for codings. The coder specified in \"Astade.ini\" is used as default." , wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
		    { wxCMD_LINE_OPTION, "S", "statechart-coder","Specify the statechart coder to use for codings. The statechart coder specified in \"Astade.ini\" is used as default." , wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
		    { wxCMD_LINE_SWITCH, "X", "clean",			"All files (except \"ModelNode.ini\") in the output directory are deleted before the coding starts."},
		    { wxCMD_LINE_SWITCH, "q", "quiet",			"Don't show any success and progress messages."},
		    { wxCMD_LINE_NONE }
		};

		wxCmdLineParser aCmdLineParser(argc,argv);
		aCmdLineParser.SetDesc(cmdLineDesc);
		aCmdLineParser.SetLogo("\nAstadeGenerate: the \"command line component generator\"\n" COPYRIGHT);

		if (aCmdLineParser.Parse()!=0)
		{
			wxUninitialize();
			return EXIT_FAILURE;
		}

		wxFileConfig fileConfig("Astade.ini");

		bool quiet = aCmdLineParser.Found("q");

		// find out the component
		wxString componentName;
		if (!aCmdLineParser.Found("c",&componentName))
			fileConfig.Read("TreeView/ActiveComponent",&componentName,wxEmptyString);

		if (componentName.empty())
		{
			if (!quiet)
				printf("Cannot find an active component\n");
			wxUninitialize();
			return EXIT_FAILURE;
		}

		wxFileName componentFileName(componentName);
		componentFileName.SetFullName("ModelNode.ini");

		// find out the target path
		wxString outputPath;
		if (!aCmdLineParser.Found("d",&outputPath))
		{
			wxFileName aFileName(componentFileName);
			aFileName.AppendDir("auto");
			outputPath = aFileName.GetPath();
		}

		if (!wxFileName::DirExists(outputPath))
		{
			if (!quiet)
				printf("Directory \"%s\" does not exist\n",outputPath.c_str());
			wxUninitialize();
			return EXIT_FAILURE;
		}

		// find out the coder
		wxString coderName;
		if (!aCmdLineParser.Found("C",&coderName))
			fileConfig.Read("Tools/Coder",&coderName,wxEmptyString);

		if (!wxFileName::FileExists(coderName))
		{
			if (!quiet)
				printf("Cannot find a coder\n");
			wxUninitialize();
			return EXIT_FAILURE;
		}

		// find out the statechart coder
		wxString statechartCoderName;
		if (!aCmdLineParser.Found("S",&statechartCoderName))
			fileConfig.Read("Tools/StatechartCoder",&statechartCoderName,wxEmptyString);

		if (!wxFileName::FileExists(statechartCoderName))
		{
			if (!quiet)
				printf("Cannot find a statechart-coder\n");
			wxUninitialize();
			return EXIT_FAILURE;
		}

		if (aCmdLineParser.Found("X"))
		{
			if (!quiet)
				printf("Emptying output Directory \"%s\"\n",outputPath.c_str());

			wxArrayString names;
			wxFileName deleteFile;
			deleteFile.AssignDir(outputPath);

			wxDir::GetAllFiles(outputPath, &names, wxEmptyString, wxDIR_FILES);

			for (unsigned int i=0; i<names.GetCount();i++)
			{
				deleteFile.SetFullName(names[i]);

				if (deleteFile.GetFullName() != "ModelNode.ini")
				{
					wxRemoveFile(deleteFile.GetFullPath());
					if (!quiet)
						printf(".");
				}
			}

			if (!quiet)
				printf("done.\n");
		}

		AdeModelElement* anElement = AdeModelElement::CreateNewElement(componentFileName);
		AdeComponent* aComponent = dynamic_cast<AdeComponent*>(anElement);

		if (aComponent == 0)
		{
			if (!quiet)
				printf("%s is not a valid component\n",componentName.c_str());
			wxUninitialize();
			return EXIT_FAILURE;
		}

		if (!quiet)
		{
			printf("Generating component \"%s\" from file %s\n(Files are written to: %s)\n\n",aComponent->GetName().c_str(), componentFileName.GetFullPath().c_str(),outputPath.c_str());
			printf("Generating classes: (Coder: %s)\n\n",coderName.c_str());
		}

		AdeElementIterator it;

		wxFileName modelRoot = aComponent->GetFileName();
		modelRoot.RemoveLastDir();
		modelRoot.RemoveLastDir();

		wxFileName saveCWD = wxFileName::GetCwd();
		wxFileName::SetCwd(modelRoot.GetPath());

		for (it = aComponent->GetFirstBelongingClass(); it != aComponent->end(); ++it)
		{
			anElement = it.CreateNewElement();
			wxString command = wxString("\"") + coderName + "\" \"" + anElement->GetFileName().GetFullPath() + "\" \"" + outputPath + "/" + anElement->GetName() + ".cpp\"";
			if (!quiet)
				printf("%s:\n%s\n",anElement->GetName().c_str(),command.c_str());
			wxExecute(command,wxEXEC_SYNC);
			delete anElement;
		}
		if (!quiet)
			printf("\nGenerating code from statecharts: (Coder: %s)\n\n",statechartCoderName.c_str());

		for (it = aComponent->GetFirstBelongingStatechart(); it != aComponent->end(); ++it)
		{
			anElement = it.CreateNewElement();
			wxString command = wxString("\"") + statechartCoderName + "\" \"" + anElement->GetFileName().GetFullPath() + "\" \"" + outputPath + "/" + anElement->GetName() + ".cpp\"";
			if (!quiet)
				printf("%s:\n%s\n",anElement->GetName().c_str(),command.c_str());
			wxExecute(command,wxEXEC_SYNC);
			delete anElement;
		}

		wxFileName::SetCwd(saveCWD.GetPath());

		wxUninitialize();
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
