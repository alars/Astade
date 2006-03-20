#include "RCtrlDialog.h"

BEGIN_EVENT_TABLE(RCtrlDialog, wxDialog)

	EVT_CLOSE(RCtrlDialog::Close)
	EVT_BUTTON(ID_SELECT_FILE, RCtrlDialog::FileBrowse)
	EVT_RADIOBOX(ID_SELECT_REVISIONCONTROL, RCtrlDialog::SelectRevisionControl)

END_EVENT_TABLE()