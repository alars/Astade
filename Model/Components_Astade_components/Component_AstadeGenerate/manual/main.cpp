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
            { wxCMD_LINE_OPTION, wxS("C"), wxS("coder"), wxS("Specify the coder to use for \"C++\" classes. The coder specified in \"Astade.ini\" is used as default."), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
            { wxCMD_LINE_OPTION, wxS("a"), wxS("ccoder"), wxS("Specify the coder to use for \"C\" classes. The coder specified in \"Astade.ini\" is used as default."), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
            { wxCMD_LINE_OPTION, wxS("S"), wxS("statechart-coder"), wxS("Specify the statechart coder to use for codings. The statechart coder specified in \"Astade.ini\" is used as default."), wxCMD_LINE_VAL_STRING, wxCMD_LINE_PARAM_OPTIONAL },
            { wxCMD_LINE_SWITCH, wxS("X"), wxS("clean"), wxS("All files (except \"ModelNode.ini\" and \"Makefile\") in the output directory are deleted before the coding starts.") },
            { wxCMD_LINE_SWITCH, wxS("M"), wxS("MM"), wxS("Don't generate the files, but generate an makefile include.") },
            { wxCMD_LINE_SWITCH, wxS("F"), wxS("files"), wxS("Don't generate the files, but make a list of all files to generate.") },
            { wxCMD_LINE_SWITCH, wxS("q"), wxS("quiet"), wxS("Don't show any success and progress messages.") },
            { wxCMD_LINE_NONE }
        };

        wxCmdLineParser aCmdLineParser(argc, argv);
        aCmdLineParser.SetDesc(cmdLineDesc);
        aCmdLineParser.SetLogo(wxS("\nAstadeGenerate: the \"command line component generator\"\n" COPYRIGHT));

        if (aCmdLineParser.Parse() != 0)
        {
            wxUninitialize();
            return EXIT_FAILURE;
        }

        wxFileConfig fileConfig(wxS("Astade.ini"));

        bool quiet = aCmdLineParser.Found(wxS("q"));
        bool generateInclude = aCmdLineParser.Found(wxS("M"));
        bool fileList = aCmdLineParser.Found(wxS("F"));

        if (generateInclude)
            quiet = true;

        if (fileList)
        {
            quiet = true;
            generateInclude = false;
        }

        // find the component
        wxString componentName;
        if (!aCmdLineParser.Found(wxS("c"), &componentName))
            fileConfig.Read(wxS("TreeView/ActiveComponent"), &componentName, wxEmptyString);

        if (componentName.empty())
        {
            if (!quiet)
                printf("Cannot find an active component\n");
            wxUninitialize();
            return EXIT_FAILURE;
        }

        wxFileName componentFileName(componentName);
        componentFileName.SetFullName(wxS("ModelNode.ini"));

        // find the target path
        wxString outputPath;
        if (!aCmdLineParser.Found(wxS("d"), &outputPath))
        {
            wxFileName aFileName(componentFileName);
            aFileName.AppendDir(wxS("auto"));
            aFileName.MakeAbsolute();
            outputPath = aFileName.GetPath();
        }

        if (!wxFileName::DirExists(outputPath))
        {
            if (aCmdLineParser.Found(wxS("f")))
            {
                if (!wxFileName::Mkdir(outputPath, 0755, wxPATH_MKDIR_FULL))
                {
                    if (!quiet)
                        printf("Could not create \"%s\"\n", (const char*)outputPath.utf8_str());
                    wxUninitialize();
                    return EXIT_FAILURE;
                }
            }
            else
            {
                if (!quiet)
                    printf("Directory \"%s\" does not exist\n", (const char*)outputPath.utf8_str());
                wxUninitialize();
                return EXIT_FAILURE;
            }
        }

        // find the coder
        wxString cppCoderName;
        wxString cCoderName;
        if (!aCmdLineParser.Found(wxS("C"), &cppCoderName))
            fileConfig.Read(wxS("Tools/Coder"), &cppCoderName, wxEmptyString);
        if (!aCmdLineParser.Found(wxS("a"), &cCoderName))
            fileConfig.Read(wxS("Tools/CCoder"), &cCoderName, wxEmptyString);

        // find the statechart coder
        wxString statechartCoderName;
        if (!aCmdLineParser.Found(wxS("S"), &statechartCoderName))
            fileConfig.Read(wxS("Tools/StatechartCoder"), &statechartCoderName, wxEmptyString);

        if (aCmdLineParser.Found(wxS("X")))
        {
            if (!quiet)
                printf("Emptying output Directory \"%s\"\n", (const char*)outputPath.utf8_str());

            wxArrayString names;
            wxFileName deleteFile;
            deleteFile.AssignDir(outputPath);

            wxDir::GetAllFiles(outputPath, &names, wxEmptyString, wxDIR_FILES);

            for (unsigned int i = 0; i < names.GetCount(); i++)
            {
                deleteFile.SetFullName(names[i]);
                if (deleteFile.GetFullName() != wxS("ModelNode.ini") && deleteFile.GetFullName() != wxS("Makefile") && !deleteFile.GetName().StartsWith(wxS(".")))
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
                printf("%s is not a valid component\n", (const char*)componentName.utf8_str());
            wxUninitialize();
            return EXIT_FAILURE;
        }

        if (!quiet)
        {
            printf("Generating component \"%s\" from file %s\n(Files are written to: %s)\n\n", (const char*)aComponent->GetName().utf8_str(), (const char*)componentFileName.GetFullPath().utf8_str(), (const char*)outputPath.utf8_str());
            printf("Generating classes: (Coder: %s)\n\n", (const char*)cppCoderName.utf8_str());
            printf("Generating 'C'-classes: (Coder: %s)\n\n", (const char*)cCoderName.utf8_str());
        }

        wxFileName modelRoot = aComponent->GetFileName();
        modelRoot.RemoveLastDir();
        modelRoot.RemoveLastDir();

        wxFileName saveCWD = wxFileName::GetCwd();

        if (!quiet)
            printf("Change directory to: \"%s\"\n", (const char*)modelRoot.GetPath().utf8_str());

        wxFileName::SetCwd(modelRoot.GetPath());

        AdeElementIterator it;
        wxString ext;

        for (it = aComponent->GetFirstBelongingClass(); it != aComponent->end(); ++it)
        {
            anElement = it.CreateNewElement();
            AdeClass* aClass = dynamic_cast<AdeClass*>(anElement);
            if (!aClass)
                continue;
            wxString theCoder;
            if (aClass->codingLanguage() == CODE_C)
            {
                if (!wxFileName::FileExists(cCoderName))
                {
                    if (!quiet)
                        printf("Cannot find the C coder \"%s\"\n", (const char*)cCoderName.utf8_str());
                    wxUninitialize();
                    return EXIT_FAILURE;
                }
                theCoder = cCoderName;
            }
            else
            {
                if (!wxFileName::FileExists(cppCoderName))
                {
                    if (!quiet)
                        printf("Cannot find the C++ coder \"%s\"\n", (const char*)cppCoderName.utf8_str());
                    wxUninitialize();
                    return EXIT_FAILURE;
                }
                theCoder = cppCoderName;
            }
            ext = wxS(".") + aClass->GetImpExtension();

            if (fileList)
            {
                printf("%s ", (const char*)(anElement->GetName() + ext).utf8_str());
            }
            else if (generateInclude)
            {
                wxFileName ModelDir(componentFileName);
                ModelDir.RemoveLastDir();
                ModelDir.RemoveLastDir();

                wxFileName ModelClass(anElement->GetFileName());

                wxFileName ModelComponent(componentFileName);
                ModelComponent.MakeRelativeTo(ModelDir.GetPath());

                //implementation file
                printf("\n%s %s:%s\n",
                    (const char*)(anElement->GetName() + ext).utf8_str(),
                    (const char*)(anElement->GetName() + wxS(".h")).utf8_str(),
                    (const char*)anElement->GetFileName().GetFullPath().utf8_str());

                printf("\t@echo generating %s\n",
                    (const char*)anElement->GetName().utf8_str());

                printf("\t@cd %s;%s %s %s/%s %s\n",
                    (const char*)ModelDir.GetPath().utf8_str(),
                    (const char*)theCoder.utf8_str(),
                    (const char*)ModelClass.GetFullPath().utf8_str(),
                    (const char*)outputPath.utf8_str(),
                    (const char*)(anElement->GetName() + ext).utf8_str(),
                    (const char*)ModelComponent.GetFullPath().utf8_str());
            }
            else
            {
                wxString command = wxS("\"") + theCoder + wxS("\" \"")
                    + anElement->GetFileName().GetFullPath() + wxS("\" \"")
                    + outputPath + wxS("/") + anElement->GetName() + ext + wxS("\" \"")
                    + componentFileName.GetFullPath() + wxS("\"");
                if (!quiet)
                    printf("%s:\n%s\n", (const char*)anElement->GetName().utf8_str(), (const char*)command.utf8_str());
                wxExecute(command, wxEXEC_SYNC);
            }
            delete anElement;
        }
        if (!quiet)
            printf("\nGenerating code from statecharts: (Coder: %s)\n\n", (const char*)statechartCoderName.utf8_str());

        for (it = aComponent->GetFirstBelongingStatechart(); it != aComponent->end(); ++it)
        {
            anElement = it.CreateNewElement();

            AdeStatechart* aStateChart = dynamic_cast<AdeStatechart*>(anElement);

            if (aStateChart == 0)
                wxLogFatalError(wxS("Cannot generate because the item is no Statechart"));

            // Add the coder suffix to the name
            wxFileName theCoder(statechartCoderName);
            wxString coderBaseName = theCoder.GetName();
            coderBaseName += aStateChart->GetCoderSuffix();
            theCoder.SetName(coderBaseName);

            if (!wxFileName::FileExists(theCoder.GetFullPath()))
            {
                if (!quiet)
                    printf("Cannot find the statechart-coder\n");
                wxUninitialize();
                return EXIT_FAILURE;
            }

            wxString command = wxS("\"") + theCoder.GetFullPath() + wxS("\" \"") + anElement->GetFileName().GetFullPath() + wxS("\" \"") + outputPath + wxS("/") + anElement->GetName() + wxS(".cpp\"");
            if (!quiet)
                printf("%s:\n%s\n", (const char*)anElement->GetName().utf8_str(), (const char*)command.utf8_str());

            if (fileList)
            {
                printf("%s ", (const char*)(anElement->GetName() + ext).utf8_str());
            }
            else if (generateInclude)
             {
                wxFileName ModelDir(componentFileName);
                ModelDir.RemoveLastDir();
                ModelDir.RemoveLastDir();

                wxFileName ModelClass(anElement->GetFileName());

                //implementation file
                printf("\n%s %s:%s\n",
                    (const char*)(anElement->GetName() + ext).utf8_str(),
                    (const char*)(anElement->GetName() + wxS(".h")).utf8_str(),
                    (const char*)anElement->GetFileName().GetFullPath().utf8_str());

                printf("\t@echo generating %s\n",
                    (const char*)anElement->GetName().utf8_str());

                printf("\t@cd %s;%s %s %s/%s\n",
                    (const char*)ModelDir.GetPath().utf8_str(),
                    (const char*)coderBaseName.utf8_str(),
                    (const char*)ModelClass.GetFullPath().utf8_str(),
                    (const char*)outputPath.utf8_str(),
                    (const char*)(anElement->GetName() + ext).utf8_str());
            }
            else
                wxExecute(command, wxEXEC_SYNC);
            delete anElement;
        }

        if (!quiet)
            printf("Change back to directory: \"%s\"\n", (const char*)saveCWD.GetPath().utf8_str());

        wxFileName::SetCwd(saveCWD.GetPath());

        wxUninitialize();
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
