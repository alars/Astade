#include "SeqFrame.h"

BEGIN_EVENT_TABLE(SeqFrame,wxFrame)
	EVT_CLOSE(SeqFrame::Exit)
	EVT_MENU(ID_OPEN, SeqFrame::Open)
	EVT_MENU(ID_SAVE, SeqFrame::Save)
	EVT_MENU(ID_SAVEGRAPH, SeqFrame::SaveGraphic)
	EVT_MENU(ID_SAVEAS, SeqFrame::SaveFileAs)
	EVT_MENU(ID_ABOUT, SeqFrame::About)
	EVT_NOTEBOOK_PAGE_CHANGED(ID_NOTEBOOK, SeqFrame::GenText)
END_EVENT_TABLE()