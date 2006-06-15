#include "UseFrame.h"

BEGIN_EVENT_TABLE(UseFrame,wxFrame)
	EVT_MENU(ID_SAVE, UseFrame::Save)
	EVT_MENU(ID_SAVEAS, UseFrame::SaveFileAs)
	EVT_MENU(ID_ABOUT, UseFrame::About)
END_EVENT_TABLE()
