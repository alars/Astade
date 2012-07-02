#include <wx/wx.h>
#include <wx/filename.h>
#include <wx/string.h>

int main(int argc, char *argv[])
{
    wxInitializer initializer;
	wxFileName currentDir;
	currentDir.AssignDir(wxGetCwd());

    printf("\n\n");

    printf("wxGetCwd() reports: %s\n", wxGetCwd().utf8_str());
    printf("wxFileName::GetCwd reports: %s\n", wxFileName::GetCwd().utf8_str());
    printf("wxFileName::GetHomeDir reports: %s\n", wxFileName::GetHomeDir().utf8_str());
    
    wxFileName aFilename("/");
    
    aFilename.MakeRelativeTo();
    
    printf("root is: %s\n", aFilename.GetFullPath().utf8_str());
    
    printf("\n\n");
   
    return EXIT_SUCCESS;
}
