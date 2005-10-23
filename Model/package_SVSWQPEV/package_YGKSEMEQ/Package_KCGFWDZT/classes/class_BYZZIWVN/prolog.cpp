#include <wx/wxprec.h>
#undef wxUSE_RESOURCES
#define wxUSE_RESOURCES 1
#include <wx/utils.h>
#include <wx/timer.h>
#include "ResourceEdit.h"

BEGIN_EVENT_TABLE(ResourceEdit,wxDialog)

	EVT_CLOSE(ResourceEdit::ResourceEditClose)
	EVT_INIT_DIALOG(ResourceEdit::InitDialog)
	EVT_BUTTON(ID_CANCEL,ResourceEdit::Cancel)
	EVT_BUTTON(ID_SAVEANDEXIT,ResourceEdit::Save)
	EVT_CHECKBOX(ID_VIRTUAL, ResourceEdit::UncheckStatic)
	EVT_CHECKBOX(ID_STATIC, ResourceEdit::UncheckVirtual)
	EVT_CHECKBOX(ID_ABSTRACT, ResourceEdit::CheckVirtual)
	EVT_TEXT(ID_AGREGATIONTYPE, ResourceEdit::ChangeIcon)

END_EVENT_TABLE()