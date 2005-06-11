#include "Astade.h"
#include "AstadeFrame.h"

IMPLEMENT_APP(Astade)

bool Astade::OnInit()
{
    AstadeFrame *myFrame = new  AstadeFrame();
	SetTopWindow(myFrame);
	myFrame->Show(TRUE);		
	return TRUE;
}
 
int Astade::OnExit()
{
	return 0;
}
