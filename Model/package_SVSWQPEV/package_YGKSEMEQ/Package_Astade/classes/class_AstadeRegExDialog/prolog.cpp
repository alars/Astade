#include "AstadeRegExDialog.h"

BEGIN_EVENT_TABLE(AstadeRegExDialog,wxDialog)
	EVT_CLOSE(AstadeRegExDialog::DlgClose)
	EVT_BUTTON(wxID_CANCEL, AstadeRegExDialog::DlgCancel)
	EVT_BUTTON(wxID_OK, AstadeRegExDialog::DlgSaveAndExit)
	EVT_BUTTON(ID_DEFAULT, AstadeRegExDialog::SetDefault)
END_EVENT_TABLE()
