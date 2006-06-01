#include "UsePanel.h"

BEGIN_EVENT_TABLE(UsePanel, GrafPanel)
	EVT_RIGHT_DOWN(UsePanel::ContextMenu)
	EVT_MENU(ID_ADDUSECASE, UsePanel::AddUseCase)
END_EVENT_TABLE()
