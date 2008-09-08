#include "AstadeDirDialog.h"
#include <wx/filedlg.h>

#ifndef wxDD_DIR_MUST_EXIST
# define wxDD_DIR_MUST_EXIST 0
#endif

BEGIN_EVENT_TABLE(AstadeDirDialog,wxDialog)
	EVT_CLOSE(AstadeDirDialog::DlgClose)
	EVT_BUTTON(wxID_CANCEL, AstadeDirDialog::DlgCancel)
	EVT_BUTTON(wxID_OK, AstadeDirDialog::DlgSaveAndExit)
	EVT_BUTTON(ID_DEFAULT, AstadeDirDialog::SetDefault)
	EVT_BUTTON(IDMODELPATHBROWSE, AstadeDirDialog::ModelPathBrowse)
	EVT_BUTTON(IDHELPPATHBROWSE, AstadeDirDialog::HelpPathBrowse)
	EVT_BUTTON(IDFEATUREEDITPATHBROWSE, AstadeDirDialog::FeatureEditPathBrowse)
	EVT_BUTTON(IDCODEEDITPATHBROWSE, AstadeDirDialog::CodeEditPathBrowse)
	EVT_BUTTON(IDOMDPATHBROWSE, AstadeDirDialog::OmdViewPathBrowse)
	EVT_BUTTON(IDSTATECHARTPATHBROWSE, AstadeDirDialog::StatechartViewPathBrowse)
	EVT_BUTTON(IDCODERPATHBROWSE, AstadeDirDialog::CoderPathBrowse)
	EVT_BUTTON(IDCCODERPATHBROWSE, AstadeDirDialog::CCoderPathBrowse)
	EVT_BUTTON(IDSTATECHARTCODERBROWSE, AstadeDirDialog::StatechartCoderPathBrowse)
	EVT_BUTTON(IDMAKEPATHBROWSE, AstadeDirDialog::MakePathBrowse)
	EVT_BUTTON(IDSOUNDPATHBROWSE, AstadeDirDialog::SoundPathBrowse)
	EVT_BUTTON(IDSEQUENCESBROWSE, AstadeDirDialog::SequencesPathBrowse)
	EVT_BUTTON(IDUSECASEEDIT, AstadeDirDialog::UseCasePathBrowse)
	EVT_BUTTON(IDTEMPLATESPATHBROWSE, AstadeDirDialog::TemplatesPathBrowse)
	EVT_BUTTON(IDHTMLBROWSERPATHBROWSE, AstadeDirDialog::HtmlBrowserPathBrowse)
	EVT_BUTTON(IDDOCWIZBROWSE, AstadeDirDialog::DoxWizBrowse)
END_EVENT_TABLE()
