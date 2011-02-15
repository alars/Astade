#include <wx/wx.h>
#include <wx/filename.h>
#include <wx/string.h>

int main(int argc, char *argv[])
{
    wxInitializer initializer;
	wxFileName currentDir;
	currentDir.AssignDir(wxGetCwd());

    printf("\n\n");

    printf("wxGetCwd() reports: %s\n", wxGetCwd().c_str());
    printf("wxFileName::GetCwd reports: %s\n", wxFileName::GetCwd().c_str());
    printf("wxFileName::GetHomeDir reports: %s\n", wxFileName::GetHomeDir().c_str());
    
    wxFileName aFilename("/");
    
    aFilename.MakeRelativeTo();
    
    printf("root is: %s\n",aFilename.GetFullPath().c_str());
    
    printf("\n\n");
   
    return EXIT_SUCCESS;
}
