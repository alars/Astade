#include "GrafNode.h"

BEGIN_EVENT_TABLE(GrafNode, wxEvtHandler)
	EVT_LEFT_DCLICK(GrafNode::OnDClick)
	EVT_LEFT_DOWN(GrafNode::OnClick)
	EVT_MOTION(GrafNode::MouseMotion)
	EVT_MENU(-1, GrafNode::Pinned)
END_EVENT_TABLE()
