/* vi: set tabstop=4: */

#include <wx/wxprec.h>
#include <wx/utils.h>
#include <wx/sizer.h>
#include <wx/statbox.h>

#include "ResourceEdit.h"

#include "edit.xpm"
#include "parameter.xpm"
#include "class.xpm"
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
#include "privop.xpm"
#include "protop.xpm"
#include "Statechart.xpm"
#include "State.xpm"
#include "Transition.xpm"
#include "InternalTransition.xpm"
#include "SelfTransition.xpm"
#include "libClass.xpm"
#include "friend.xpm"


BEGIN_EVENT_TABLE(ResourceEdit, wxDialog)

	EVT_CLOSE(ResourceEdit::ResourceEditClose)
	EVT_INIT_DIALOG(ResourceEdit::InitDialog)
	EVT_BUTTON(wxID_CANCEL,			ResourceEdit::Cancel)
	EVT_BUTTON(wxID_OK,				ResourceEdit::Save)
	EVT_CHECKBOX(ID_VIRTUAL,		ResourceEdit::UncheckStatic)
	EVT_CHECKBOX(ID_INLINE,			ResourceEdit::UncheckVirtual)
	EVT_CHECKBOX(ID_STATIC,			ResourceEdit::UncheckVirtual)
	EVT_CHECKBOX(ID_ABSTRACT,		ResourceEdit::CheckVirtual)
	EVT_TEXT(ID_AGGREGATIONTYPE,	ResourceEdit::ChangeIcon)
	EVT_RADIOBUTTON(ID_M_PRIVATE,	ResourceEdit::ChangeIcon)
	EVT_RADIOBUTTON(ID_M_PROTECTED,	ResourceEdit::ChangeIcon)
	EVT_RADIOBUTTON(ID_M_PUBLIC,	ResourceEdit::ChangeIcon)

END_EVENT_TABLE()
