lastMouseEvent = event.GetPosition();

if (!IsInArea(lastMouseEvent))
{
	event.Skip();
	return;
}

m_Parent->selectedNode = this;
m_Parent->Refresh();