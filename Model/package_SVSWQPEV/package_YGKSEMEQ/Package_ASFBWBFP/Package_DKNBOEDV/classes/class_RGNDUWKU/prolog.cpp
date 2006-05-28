#include "GrafNode.h"

BEGIN_EVENT_TABLE(GrafNode, wxControl)
	EVT_PAINT(GrafNode::OnPaint)
	EVT_ENTER_WINDOW(GrafNode::OnMouseEnterWindow)
END_EVENT_TABLE()
