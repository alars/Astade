#include "AstadeMakeOutputEdit.h"

BEGIN_EVENT_TABLE(AstadeMakeOutputEdit,wxTextCtrl)
	EVT_CONTEXT_MENU(AstadeMakeOutputEdit::ContextMenu)
	EVT_MENU(ID_EDIT_ERROR, AstadeMakeOutputEdit::Edit)
	EVT_MENU(ID_EDIT_ERROR_ELEMENT, AstadeMakeOutputEdit::Edit)
	EVT_END_PROCESS(wxID_ANY, AstadeMakeOutputEdit::EndProcess)
END_EVENT_TABLE()
