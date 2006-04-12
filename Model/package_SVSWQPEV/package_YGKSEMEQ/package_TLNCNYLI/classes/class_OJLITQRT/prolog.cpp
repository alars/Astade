#include "AstadeMakeOutputEdit.h"

BEGIN_EVENT_TABLE(AstadeMakeOutputEdit,wxTextCtrl)
	EVT_CONTEXT_MENU(AstadeMakeOutputEdit::ContextMenu)
	EVT_MENU(ID_EDIT_ERROR, AstadeMakeOutputEdit::Edit)
END_EVENT_TABLE()
