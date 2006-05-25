#include "GrafNode.h"

BEGIN_EVENT_TABLE(GrafNode, wxControl)
	EVT_TIMER(wxID_ANY,GrafNode::CalculatePosition)
	EVT_PAINT(GrafNode::OnPaint)
END_EVENT_TABLE()
