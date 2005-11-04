#include <wx/wx.h>
#include <wx/string.h>
#include <wx/filename.h>
#include <wx/treectrl.h>
#include <wx/config.h>
#include <wx/confbase.h>
#include <wx/fileconf.h>
#include <wx/filefn.h>


int main(int argc, char *argv[])
{
    wxInitializer initializer;
	wxConfigBase::Set(new wxFileConfig("Astade.ini"));
	wxConfigBase* theConfig = wxConfigBase::Get();
	wxFileName currentDir;
	currentDir.AssignDir(wxGetCwd());

	theConfig->Write("TreeView/Release","0.1.0");
    currentDir.SetFullName("help.zip");
	theConfig->Write("TreeView/Helpfile",currentDir.GetFullPath());
    currentDir.SetFullName("ResourceEdit.exe");
	theConfig->Write("Tools/FeatureEdit",currentDir.GetFullPath());
    currentDir.SetFullName("omd.bat");
	theConfig->Write("Tools/OmdViewPath",currentDir.GetFullPath());
    currentDir.SetFullName("QDC.exe");
	theConfig->Write("Tools/Coder",currentDir.GetFullPath());
    currentDir.SetFullName("LiteEdit.exe");
	theConfig->Write("Tools/CodeEdit",currentDir.GetFullPath());
    wxFileName ModelDir(currentDir);
    ModelDir.AppendDir("Model");
	theConfig->Write("TreeView/ModelPath",ModelDir.GetPath());
    currentDir.AppendDir("Templates");
	theConfig->Write("TreeView/TemplatesPath",currentDir.GetPath());

	theConfig->Flush();

	currentDir.AssignDir(wxGetCwd());
    currentDir.SetFullName("omd.bat");
    FILE* f;
    f = fopen(currentDir.GetFullPath().c_str(),"w");
    currentDir.SetFullName("omd.exe");


	fprintf(f,"\"%s\" %%1 > \"%%TMP%%\\omd.dot\"\n",currentDir.GetFullPath().c_str());
	fprintf(f,"dot \"%%TMP%%\\omd.dot\" -Tpng -o\"%%TMP%%\\omd.png\"\n");
	fprintf(f,"\"%%TMP%%\\omd.png\"\n");
	fprintf(f,"del \"%%TMP%%\\omd.png\"\n");
	fprintf(f,"del \"%%TMP%%\\omd.dot\"\n");

    return EXIT_SUCCESS;
}
