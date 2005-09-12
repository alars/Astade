#include "AstadeFrame.h"
BEGIN_EVENT_TABLE(AstadeFrame,wxFrame)
	EVT_TREE_ITEM_EXPANDING(ID_ASTADETREE, AstadeFrame::ExpandNode)
	EVT_TREE_ITEM_COLLAPSED(ID_ASTADETREE, AstadeFrame::CollapseNode)
	EVT_TREE_ITEM_RIGHT_CLICK(ID_ASTADETREE,AstadeFrame::OnRightMouseClick)
	EVT_MENU(ID_MNU_HELP, AstadeFrame::DisplayHelp)
	EVT_MENU(ID_MNU_INFO, AstadeFrame::DisplayInfo)
	EVT_MENU(ID_SETEDITORS, AstadeFrame::DirDialog)
END_EVENT_TABLE()
