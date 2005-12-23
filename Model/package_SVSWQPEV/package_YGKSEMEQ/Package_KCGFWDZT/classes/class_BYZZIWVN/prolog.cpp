#include <wx/wxprec.h>
#undef wxUSE_RESOURCES
#define wxUSE_RESOURCES 1
#include <wx/utils.h>
#include <wx/timer.h>
#include "ResourceEdit.h"
#include <wx/sizer.h>
#include <wx/statbox.h>

#include "edit.xpm"
#include "parameter.xpm"
#include "class.xpm"
#include "component.xpm"
#include "attribute.xpm"
#include "privAttr.xpm"
#include "protAttr.xpm"
#include "operation.xpm"
#include "const.xpm"
#include "privconst.xpm"
#include "protconst.xpm"
#include "dest.xpm"
#include "privdest.xpm"
#include "protdest.xpm"
#include "imprelation.xpm"
#include "specrelation.xpm"
#include "association.xpm"
#include "aggregation.xpm"
#include "composition.xpm"
#include "generalisation.xpm"
#include "Type.xpm"
#include "components.xpm"
#include "package.xpm"
#include "configuration.xpm"
#include "privop.xpm"
#include "protop.xpm"
#include "Statechart.xpm"
#include "State.xpm"
#include "Transition.xpm"
#include "InternalTransition.xpm"
#include "SelfTransition.xpm"
#include "libClass.xpm"


BEGIN_EVENT_TABLE(ResourceEdit,wxDialog)

	EVT_CLOSE(ResourceEdit::ResourceEditClose)
	EVT_INIT_DIALOG(ResourceEdit::InitDialog)
	EVT_BUTTON(ID_CANCEL,ResourceEdit::Cancel)
	EVT_BUTTON(ID_SAVEANDEXIT,ResourceEdit::Save)
	EVT_CHECKBOX(ID_VIRTUAL, ResourceEdit::UncheckStatic)
	EVT_CHECKBOX(ID_STATIC, ResourceEdit::UncheckVirtual)
	EVT_CHECKBOX(ID_ABSTRACT, ResourceEdit::CheckVirtual)
	EVT_TEXT(ID_AGREGATIONTYPE, ResourceEdit::ChangeIcon)
	EVT_RADIOBUTTON(ID_M_PRIVATE, ResourceEdit::ChangeIcon)
	EVT_RADIOBUTTON(ID_M_PROTECTED, ResourceEdit::ChangeIcon)
	EVT_RADIOBUTTON(ID_M_PUBLIC, ResourceEdit::ChangeIcon)

END_EVENT_TABLE()