#include "AstadeFrame.h"
#include "AstadeOmdDialog.h"

BEGIN_EVENT_TABLE(AstadeOmdDialog,wxDialog)
	EVT_BUTTON(wxID_OK, AstadeOmdDialog::DisplayOMD)
END_EVENT_TABLE()
