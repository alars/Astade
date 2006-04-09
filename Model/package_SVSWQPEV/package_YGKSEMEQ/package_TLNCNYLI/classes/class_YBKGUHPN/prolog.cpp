#include "AstadeRegExDialog.h"

BEGIN_EVENT_TABLE(AstadeRegExDialog,wxDialog)
	EVT_CLOSE(AstadeRegExDialog::DlgClose)
	EVT_BUTTON(wxID_CANCEL, AstadeRegExDialog::DlgCancel)
	EVT_BUTTON(wxID_OK, AstadeRegExDialog::DlgSaveAndExit)
END_EVENT_TABLE()
