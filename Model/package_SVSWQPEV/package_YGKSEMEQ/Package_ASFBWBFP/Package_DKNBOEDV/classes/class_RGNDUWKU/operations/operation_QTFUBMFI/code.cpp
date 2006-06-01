wxPoint aPosition = ClientToScreen(event.GetPosition());

if (event.Dragging())
{
	int dx = aPosition.x - lastMouseEvent.x;
	int dy = aPosition.y - lastMouseEvent.y;
	m_Position += GrafVector(dx,dy);
	Move(m_Position.xCoord(),m_Position.yCoord());
}

lastMouseEvent = aPosition;