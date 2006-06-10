lastMouseEvent = event.GetPosition();
if (!IsInArea(lastMouseEvent))
{
	event.Skip();
	return;
}

SetSelectedNode(NULL);
m_Parent->Refresh();