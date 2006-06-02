#include "GrafNode.h"

BEGIN_EVENT_TABLE(GrafNode, wxEvtHandler)
	EVT_ENTER_WINDOW(GrafNode::OnMouseEnterWindow)
	EVT_LEAVE_WINDOW(GrafNode::OnMouseEnterWindow)
	EVT_LEFT_DOWN(GrafNode::OnClick)
	EVT_MOTION(GrafNode::MouseMotion)
END_EVENT_TABLE()
