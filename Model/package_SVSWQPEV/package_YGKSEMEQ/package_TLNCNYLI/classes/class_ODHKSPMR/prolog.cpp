#include "AstadeFrame.h"
BEGIN_EVENT_TABLE(AstadeFrame,wxFrame)
	EVT_MENU(ID_MNU_HELP, AstadeFrame::DisplayHelp)
	EVT_MENU(ID_MNU_INFO, AstadeFrame::DisplayInfo)
	EVT_MENU(ID_SETEDITORS, AstadeFrame::DirDialog)
END_EVENT_TABLE()
