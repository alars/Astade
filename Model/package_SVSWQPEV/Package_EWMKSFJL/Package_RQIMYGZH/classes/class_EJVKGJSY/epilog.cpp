BEGIN_EVENT_TABLE(glEdgePointer, glGraphicElement)
	EVT_MOTION(glEdgePointer::OnMouseMove)
	EVT_LEAVE_WINDOW(glEdgePointer::OnMouseLeave)
	EVT_LEFT_DOWN(glEdgePointer::OnLeftDown)
	EVT_RIGHT_DOWN(glEdgePointer::OnRightDown)
END_EVENT_TABLE()