wxPoint aPosition = event.GetPosition();
if (!IsInArea(aPosition))
{
	if (m_MouseOver)
	{
		m_MouseOver = false;
		m_Parent->Refresh();
	}
	event.Skip();
	return;
}
else
	if (!m_MouseOver)
	{
		m_MouseOver = true;
		m_Parent->Refresh();
	}

if (event.Dragging())
{
	int dx = aPosition.x - lastMouseEvent.x;
	int dy = aPosition.y - lastMouseEvent.y;
	m_Position += GrafVector(dx,dy);
	m_Parent->Refresh();
}

lastMouseEvent = aPosition;