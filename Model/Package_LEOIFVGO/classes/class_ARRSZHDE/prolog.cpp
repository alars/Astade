#include "SeqFrame.h"

BEGIN_EVENT_TABLE(SeqFrame,wxFrame)
	EVT_MENU(ID_OPEN, SeqFrame::Open)
	EVT_MENU(ID_SAVE, SeqFrame::Save)
	EVT_NOTEBOOK_PAGE_CHANGED(ID_NOTEBOOK, SeqFrame::GenText)
END_EVENT_TABLE()