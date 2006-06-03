#include "UsePanel.h"

BEGIN_EVENT_TABLE(UsePanel, GrafPanel)
	EVT_RIGHT_DOWN(UsePanel::ContextMenu)
	EVT_MENU(ID_ADDACTOR, UsePanel::Add)
	EVT_MENU(ID_ADDUSECASE, UsePanel::Add)
END_EVENT_TABLE()
