wxPoint aPosition = event.GetPosition();
event.Skip();

if (!IsInArea(aPosition))
{
	if (m_MouseOver)
	{
		m_MouseOver = false;
		m_speed = GrafVector();
		Refresh();
	}
	return;
}
else
	if (!m_MouseOver)
	{
		lastMouseEvent = aPosition;
		m_MouseOver = true;
		Refresh();
	}

if (m_MouseOver && event.Dragging())
{
	int dx = aPosition.x - lastMouseEvent.x;
	int dy = aPosition.y - lastMouseEvent.y;
	m_Position += GrafVector(dx,dy);
	m_DrawPosition = m_Position;
	myLabel->Move(m_Position.xCoord()+labelOffset.x,m_Position.yCoord()+labelOffset.y);
	m_Parent->NotifyModification();
	Refresh();
}

lastMouseEvent = aPosition;