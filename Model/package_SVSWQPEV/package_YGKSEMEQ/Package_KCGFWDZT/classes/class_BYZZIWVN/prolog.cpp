/* vi: set tabstop=4: */

#include <wx/wxprec.h>
#include <wx/utils.h>
#include <wx/sizer.h>
#include <wx/statbox.h>

#include "ResourceEdit.h"

#include "edit.xpm"
#include "parameter.xpm"
#include "imprelation.xpm"
#include "specrelation.xpm"
#include "association.xpm"
#include "aggregation.xpm"
#include "composition.xpm"
#include "generalisation.xpm"
#include "Transition.xpm"
#include "InternalTransition.xpm"
#include "SelfTransition.xpm"
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
	EVT_CHECKBOX(ID_CONST,			ResourceEdit::ChangeIcon)
	EVT_TEXT(ID_AGGREGATIONTYPE,	ResourceEdit::ChangeIcon)
	EVT_RADIOBUTTON(ID_M_PRIVATE,	ResourceEdit::ChangeIcon)
	EVT_RADIOBUTTON(ID_M_PROTECTED,	ResourceEdit::ChangeIcon)
	EVT_RADIOBUTTON(ID_M_PUBLIC,	ResourceEdit::ChangeIcon)

END_EVENT_TABLE()
