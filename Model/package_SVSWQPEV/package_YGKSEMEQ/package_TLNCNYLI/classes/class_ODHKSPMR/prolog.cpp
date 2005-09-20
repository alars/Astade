#include "AstadeFrame.h"
BEGIN_EVENT_TABLE(AstadeFrame,wxFrame)
	EVT_TREE_ITEM_EXPANDING(ID_ASTADETREE, AstadeFrame::ExpandNode)
	EVT_TREE_ITEM_COLLAPSED(ID_ASTADETREE, AstadeFrame::CollapseNode)
	EVT_TREE_ITEM_RIGHT_CLICK(ID_ASTADETREE,AstadeFrame::OnRightMouseClick)
 	EVT_TREE_SEL_CHANGED(ID_ASTADETREE,AstadeFrame::OnSelChanged)
	EVT_MENU(ID_ACTIVECONFIGURATION, AstadeFrame::SetAsActive)
	EVT_MENU(ID_ADDCLASSES, AstadeFrame::AddClassesFolder)
	EVT_MENU(ID_ADDCOMPONENTFOLDER, AstadeFrame::AddComponentFolder)
	EVT_MENU(ID_ADDCOMPONENT, AstadeFrame::AddComponent)
	EVT_MENU(ID_ADDPACKAGE, AstadeFrame::AddPackage)
	EVT_MENU(ID_FEATURES, AstadeFrame::Features)
	EVT_MENU(ID_MNU_HELP, AstadeFrame::DisplayHelp)
	EVT_MENU(ID_MNU_INFO, AstadeFrame::DisplayInfo)
	EVT_MENU(ID_SETEDITORS, AstadeFrame::DirDialog)
END_EVENT_TABLE()
