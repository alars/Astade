#include "AstadeDirDialog.h"
BEGIN_EVENT_TABLE(AstadeDirDialog,wxDialog)
	EVT_CLOSE(AstadeDirDialog::DlgClose)
	EVT_BUTTON(IDCANCEL, AstadeDirDialog::DlgCancel)
	EVT_BUTTON(IDSAVEEXIT, AstadeDirDialog::DlgSaveAndExit)
	EVT_BUTTON(IDMODELPATHBROWSE, AstadeDirDialog::ModelPathBrowse)
END_EVENT_TABLE()
