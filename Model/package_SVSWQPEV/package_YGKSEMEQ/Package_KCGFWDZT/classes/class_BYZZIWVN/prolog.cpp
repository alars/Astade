#include <wx/wxprec.h>
#undef wxUSE_RESOURCES
#define wxUSE_RESOURCES 1
#include <wx/utils.h>
#include <wx/timer.h>
#include "ResourceEdit.h"
#include <wx/sizer.h>
#include <wx/statbox.h>

#include "../Icons/edit.xpm"
#include "../Icons/parameter.xpm"
#include "../Icons/class.xpm"
#include "../Icons/component.xpm"
#include "../Icons/attribute.xpm"
#include "../Icons/operation.xpm"
#include "../Icons/const.xpm"
#include "../Icons/dest.xpm"
#include "../Icons/imprelation.xpm"
#include "../Icons/specrelation.xpm"
#include "../Icons/association.xpm"
#include "../Icons/aggregation.xpm"
#include "../Icons/composition.xpm"
#include "../Icons/generalisation.xpm"
#include "../Icons/Type.xpm"
#include "../Icons/components.xpm"
#include "../Icons/package.xpm"
#include "../Icons/configuration.xpm"

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