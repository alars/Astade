#include <wx/wx.h>
#include <wx/cmdline.h>
#include <wx/fileconf.h>
#include <wx/dir.h>
#include <AdeDefines.h>
#include <AdeModelElement.h>
#include <AdeStatechart.h>
#include <AdeComponent.h>

#if !defined(wxS)
#  define wxS(x) wxT(x)
#else
#  undef wxS
#  define wxS(x) x
#endif

int main(int argc, char** argv)
{
	if (wxInitialize())
	{
		static const wxCmdLineEntryDesc cmdLineDesc[] =
		{
			{ wxCMD_LINE_SWITCH, wxS("h"), wxS("help"), wxS("display this help screen"), wxCMD_LINE_VAL_NONE, wxCMD_LINE_OPTION_HELP },
			{ wxCMD_LINE_SWITCH, wxS("f"), wxS("force"), wxS("if the output-dir does not exist, it is created.") },
			{ wxCMD_LINE_OPTION, wxS("c"), wxS("component"), wxS("The path or \"ModelNode.ini\" of the component. The \"active\" component from \"Astade.ini\" is used as default."), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
			{ wxCMD_LINE_OPTION, wxS("d"), wxS("output-dir"), wxS("Specify a target directory for the generated files. The components \"auto\" directory is used as default."), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
			{ wxCMD_LINE_OPTION, wxS("C"), wxS("coder"), wxS("Specify the coder to use for \"C++\" codings. The coder specified in \"Astade.ini\" is used as default."), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
			{ wxCMD_LINE_OPTION, wxS("a"), wxS("ansiicoder"), wxS("Specify the coder to use for \"C\" classes. The coder specified in \"Astade.ini\" is used as default."), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
			{ wxCMD_LINE_OPTION, wxS("S"), wxS("statechart-coder"), wxS("Specify the statechart coder to use for codings. The statechart coder specified in \"Astade.ini\" is used as default."), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
			{ wxCMD_LINE_SWITCH, wxS("X"), wxS("clean"), wxS("All files (except \"ModelNode.ini\" and \"Makefile\") in the output directory are deleted before the coding starts.") },
			{ wxCMD_LINE_SWITCH, wxS("q"), wxS("quiet"), wxS("Don't show any success and progress messages.") },
		    { wxCMD_LINE_NONE }
		};

		wxCmdLineParser aCmdLineParser(argc, argv);
		aCmdLineParser.SetDesc(cmdLineDesc);
		aCmdLineParser.SetLogo("\nAstadeGenerate: the \"command line component generator\"\n" COPYRIGHT);

		if (aCmdLineParser.Parse() != 0)
		{
			wxUninitialize();
			return EXIT_FAILURE;
		}

		wxFileConfig fileConfig("Astade.ini");

		bool quiet = aCmdLineParser.Found("q");

		// find the component
		wxString componentName;
		if (!aCmdLineParser.Found("c", &componentName))
			fileConfig.Read("TreeView/ActiveComponent", &componentName, wxEmptyString);

		if (componentName.empty())
		{
			if (!quiet)
				printf("Cannot find an active component\n");
			wxUninitialize();
			return EXIT_FAILURE;
		}

		wxFileName componentFileName(componentName);
		componentFileName.SetFullName("ModelNode.ini");

		// find the target path
		wxString outputPath;
		if (!aCmdLineParser.Found("d",&outputPath))
		{
			wxFileName aFileName(componentFileName);
			aFileName.AppendDir("auto");
			outputPath = aFileName.GetPath();
		}

		if (!wxFileName::DirExists(outputPath))
		{
			if (aCmdLineParser.Found("f"))
			{
				if (!wxFileName::Mkdir(outputPath, 0755, wxPATH_MKDIR_FULL))
				{
					if (!quiet)
						printf("Could not create \"%s\"\n", (const char*)outputPath.c_str());
					wxUninitialize();
					return EXIT_FAILURE;
				}
			}
			else
			{
				if (!quiet)
					printf("Directory \"%s\" does not exist\n", (const char*)outputPath.c_str());
				wxUninitialize();
				return EXIT_FAILURE;
			}
		}

		// find the coder
		wxString cppCoderName;
		wxString cCoderName;
		if (!aCmdLineParser.Found("C", &cppCoderName))
			fileConfig.Read("Tools/Coder", &cppCoderName, wxEmptyString);
		if (!aCmdLineParser.Found("a", &cCoderName))
			fileConfig.Read("Tools/CCoder", &cCoderName, wxEmptyString);

		if (!wxFileName::FileExists(cppCoderName))
		{
			if (!quiet)
				printf("Cannot find the C++ coder \"%s\"\n", (const char*)cppCoderName.c_str());
			wxUninitialize();
			return EXIT_FAILURE;
		}

		if (!wxFileName::FileExists(cCoderName))
		{
			if (!quiet)
				printf("Cannot find the C coder \"%s\"\n", (const char*)cCoderName.c_str());
			wxUninitialize();
			return EXIT_FAILURE;
		}

		// find the statechart coder
		wxString statechartCoderName;
		if (!aCmdLineParser.Found("S", &statechartCoderName))
			fileConfig.Read("Tools/StatechartCoder", &statechartCoderName, wxEmptyString);

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
				printf("Emptying output Directory \"%s\"\n", (const char*)outputPath.c_str());

			wxArrayString names;
			wxFileName deleteFile;
			deleteFile.AssignDir(outputPath);

			wxDir::GetAllFiles(outputPath, &names, wxEmptyString, wxDIR_FILES);

			for (unsigned int i = 0; i < names.GetCount(); i++)
			{
				deleteFile.SetFullName(names[i]);
				if (deleteFile.GetFullName() != "ModelNode.ini" && deleteFile.GetFullName() != "Makefile" && !deleteFile.GetName().StartsWith("."))
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
				printf("%s is not a valid component\n", (const char*)componentName.c_str());
			wxUninitialize();
			return EXIT_FAILURE;
		}

		if (!quiet)
		{
			printf("Generating component \"%s\" from file %s\n(Files are written to: %s)\n\n", (const char*)aComponent->GetName().c_str(), (const char*)componentFileName.GetFullPath().c_str(), (const char*)outputPath.c_str());
			printf("Generating classes: (Coder: %s)\n\n", (const char*)cppCoderName.c_str());
			printf("Generating 'C'-classes: (Coder: %s)\n\n", (const char*)cCoderName.c_str());
		}

		wxFileName modelRoot = aComponent->GetFileName();
		modelRoot.RemoveLastDir();
		modelRoot.RemoveLastDir();

		wxFileName saveCWD = wxFileName::GetCwd();
		
		if (!quiet)
			printf("Change directory to: \"%s\"\n", (const char*)modelRoot.GetPath().c_str());
		
		wxFileName::SetCwd(modelRoot.GetPath());

		AdeElementIterator it;
		wxString ext;
		for (it = aComponent->GetFirstBelongingClass(); it != aComponent->end(); ++it)
		{
			anElement = it.CreateNewElement();
			AdeClass* aClass = dynamic_cast<AdeClass*>(anElement);
			wxString theCoder;
			if (aClass && aClass->IsCCoded())
			{
				ext = ".c";
				theCoder = cCoderName;
			}
			else
			{
				ext = ".cpp";
				theCoder = cppCoderName;
			}
			wxString command = wxString("\"") + theCoder + "\" \""
				+ anElement->GetFileName().GetFullPath() + "\" \""
				+ outputPath + "/" + anElement->GetName() + ext + "\" \""
				+ componentFileName.GetFullPath() + "\"";
			if (!quiet)
				printf("%s:\n%s\n", (const char*)anElement->GetName().c_str(), (const char*)command.c_str());
			wxExecute(command, wxEXEC_SYNC);
			delete anElement;
		}
		if (!quiet)
			printf("\nGenerating code from statecharts: (Coder: %s)\n\n", (const char*)statechartCoderName.c_str());

		for (it = aComponent->GetFirstBelongingStatechart(); it != aComponent->end(); ++it)
		{
			anElement = it.CreateNewElement();

			AdeStatechart* aStateChart = dynamic_cast<AdeStatechart*>(anElement);

			if (aStateChart == 0)
				wxLogFatalError("Cannot generate because the item is no Statechart");

			// Add the coder suffix to the name
			wxFileName theCoder(statechartCoderName);
			wxString coderBaseName = theCoder.GetName();
			coderBaseName += aStateChart->GetCoderSuffix();
			theCoder.SetName(coderBaseName);

			wxString command = wxString("\"") + theCoder.GetFullPath() + "\" \"" + anElement->GetFileName().GetFullPath() + "\" \"" + outputPath + "/" + anElement->GetName() + ".cpp\"";
			if (!quiet)
				printf("%s:\n%s\n", (const char*)anElement->GetName().c_str(), (const char*)command.c_str());
			wxExecute(command, wxEXEC_SYNC);
			delete anElement;
		}

		if (!quiet)
			printf("Change back to directory: \"%s\"\n", (const char*)saveCWD.GetPath().c_str());
		
		wxFileName::SetCwd(saveCWD.GetPath());

		wxUninitialize();
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
