wxPoint aPosition = event.GetPosition();
event.Skip();

if (!IsInArea(aPosition))
{
	if (m_MouseOver)
	{
		m_MouseOver = false;
		m_Parent->Refresh();
	}
	return;
}
else
	if (!m_MouseOver)
	{
		lastMouseEvent = aPosition;
		m_MouseOver = true;
		m_Parent->Refresh();
	}

if (m_MouseOver && event.Dragging())
{
	int dx = aPosition.x - lastMouseEvent.x;
	int dy = aPosition.y - lastMouseEvent.y;
	m_Position += GrafVector(dx,dy);
	m_Parent->Refresh();
}

lastMouseEvent = aPosition;