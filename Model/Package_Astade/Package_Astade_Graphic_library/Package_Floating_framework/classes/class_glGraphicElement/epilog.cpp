BEGIN_EVENT_TABLE(glGraphicElement,wxEvtHandler)
	EVT_LEFT_DCLICK(glGraphicElement::OnLeftDClick)
	EVT_RIGHT_UP(glGraphicElement::OnRightUp)
	EVT_LEFT_DOWN(glGraphicElement::OnLeftDown)
	EVT_LEFT_UP(glGraphicElement::OnLeftUp)
	EVT_LEAVE_WINDOW(glGraphicElement::OnLeftUp)
	EVT_MOTION(glGraphicElement::OnMouseMove)
END_EVENT_TABLE()