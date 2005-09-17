#include "AstadeDirDialog.h"
#include <wx/filedlg.h>

BEGIN_EVENT_TABLE(AstadeDirDialog,wxDialog)
	EVT_CLOSE(AstadeDirDialog::DlgClose)
	EVT_BUTTON(wxID_CANCEL, AstadeDirDialog::DlgCancel)
	EVT_BUTTON(IDSAVEEXIT, AstadeDirDialog::DlgSaveAndExit)
	EVT_BUTTON(IDMODELPATHBROWSE, AstadeDirDialog::ModelPathBrowse)
	EVT_BUTTON(IDHELPPATHBROWSE, AstadeDirDialog::HelpPathBrowse)
END_EVENT_TABLE()
