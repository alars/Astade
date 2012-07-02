#include <wx/wx.h>
#include <wx/string.h>
#include <wx/filename.h>
#include <wx/config.h>
#include <wx/confbase.h>
#include <wx/fileconf.h>
#include <wx/filefn.h>
#include "../../../Components_Astade_components/Component_Astade/manual/AstadeVersion.h"

int main(int argc, char *argv[])
{
    wxInitializer initializer;
	wxConfigBase::Set(new wxFileConfig("Astade.ini"));
	wxConfigBase* theConfig = wxConfigBase::Get();
	wxFileName currentDir;
	currentDir.AssignDir(wxGetCwd());

	theConfig->Write("TreeView/Release", AstadeVersion);
    currentDir.SetFullName("help.zip");
	theConfig->Write("TreeView/Helpfile", currentDir.GetFullPath());
    currentDir.SetFullName("ResourceEdit.exe");
	theConfig->Write("Tools/FeatureEdit", currentDir.GetFullPath());
    currentDir.SetFullName("sc.bat");
	theConfig->Write("Tools/StatechartViewPath", currentDir.GetFullPath());
    currentDir.SetFullName("StateChartCoder.exe");
	theConfig->Write("Tools/StatechartCoder", currentDir.GetFullPath());
    currentDir.SetFullName("csd.bat");
	theConfig->Write("Tools/CompositeStructureViewPath", currentDir.GetFullPath());
    currentDir.SetFullName("omd.bat");
	theConfig->Write("Tools/OmdViewPath", currentDir.GetFullPath());
    currentDir.SetFullName("CppGenerator.exe");
	theConfig->Write("Tools/Coder", currentDir.GetFullPath());
    currentDir.SetFullName("LiteEdit.exe");

    if (!theConfig->Exists("Tools/CodeEdit"))
    {
		theConfig->Write("Tools/CodeEdit", currentDir.GetFullPath());
		theConfig->Write("Tools/CodeEdit/editLineOption","-GL ");
	}

    currentDir.SetFullName("Trace2UML.exe");
	theConfig->Write("Tools/SequencesPath", currentDir.GetFullPath());
    currentDir.SetFullName("AstadeDraw.exe");
	theConfig->Write("Tools/UseCasesPath", currentDir.GetFullPath());
    wxFileName ModelDir(currentDir);
    ModelDir.AppendDir("Model");
    if (!theConfig->Exists("TreeView/ModelPath"))
		theConfig->Write("TreeView/ModelPath", ModelDir.GetPath());
    currentDir.AppendDir("Templates");
	theConfig->Write("TreeView/TemplatesPath", currentDir.GetPath());

    if (!theConfig->Exists("TreeView/RegEx/identifyExpression"))
		theConfig->Write("TreeView/RegEx/identifyExpression","error:|warning:");

    if (!theConfig->Exists("TreeView/RegEx/errorLineExpression"))
		theConfig->Write("TreeView/RegEx/errorLineExpression",":([0-9]+):");

    if (!theConfig->Exists("TreeView/RegEx/errorFileExpression"))
		theConfig->Write("TreeView/RegEx/errorFileExpression","(^[^:]+):");

	theConfig->Flush();

	currentDir.AssignDir(wxGetCwd());
    currentDir.SetFullName("csd.bat");
    FILE* f;
    f = fopen(currentDir.GetFullPath().utf8_str(), "w");
    currentDir.SetFullName("CSDgenerator.exe");

	fprintf(f, "\"%s\" %%1 %%2 %%3 %%4 %%5 %%6 %%7 > \"%%TMP%%\\csd.dot\"\n", (const char*)currentDir.GetFullPath().utf8_str());
	fprintf(f, "dot \"%%TMP%%\\csd.dot\" -Tpng -o\"%%TMP%%\\csd.png\"\n");
	fprintf(f, "\"%%TMP%%\\csd.png\"\n");
	fprintf(f, "del \"%%TMP%%\\csd.png\"\n");
	fprintf(f, "del \"%%TMP%%\\csd.dot\"\n");
	fclose(f);

	currentDir.AssignDir(wxGetCwd());
    currentDir.SetFullName("omd.bat");

    f = fopen(currentDir.GetFullPath().utf8_str(), "w");
    currentDir.SetFullName("OMDgenerator.exe");

	fprintf(f, "\"%s\" %%1 %%2 %%3 %%4 %%5 %%6 %%7 > \"%%TMP%%\\omd.dot\"\n", (const char*)currentDir.GetFullPath().utf8_str());
	fprintf(f, "dot \"%%TMP%%\\omd.dot\" -Tpng -o\"%%TMP%%\\omd.png\"\n");
	fprintf(f, "\"%%TMP%%\\omd.png\"\n");
	fprintf(f, "del \"%%TMP%%\\omd.png\"\n");
	fprintf(f, "del \"%%TMP%%\\omd.dot\"\n");
	fclose(f);

	currentDir.AssignDir(wxGetCwd());
    currentDir.SetFullName("sc.bat");

    f = fopen(currentDir.GetFullPath().utf8_str(), "w");
    currentDir.SetFullName("StateChartDrawer.exe");

	fprintf(f, "\"%s\" %%1 > \"%%TMP%%\\sc.dot\"\n", (const char*)currentDir.GetFullPath().utf8_str());
	fprintf(f, "dot \"%%TMP%%\\sc.dot\" -Tpng -o\"%%TMP%%\\sc.png\"\n");
	fprintf(f, "\"%%TMP%%\\sc.png\"\n");
	fprintf(f, "del \"%%TMP%%\\sc.png\"\n");
	fprintf(f, "del \"%%TMP%%\\sc.dot\"\n");
	fclose(f);

    return EXIT_SUCCESS;
}
