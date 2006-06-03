lastMouseEvent = event.GetPosition();
if (!IsInArea(lastMouseEvent))
{
	event.Skip();
	return;
}

m_Parent->selectedNode = NULL;
m_Parent->Refresh();