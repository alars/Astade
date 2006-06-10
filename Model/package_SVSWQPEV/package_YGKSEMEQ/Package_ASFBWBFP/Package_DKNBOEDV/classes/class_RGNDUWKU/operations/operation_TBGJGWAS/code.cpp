lastMouseEvent = event.GetPosition();
if (!IsInArea(lastMouseEvent))
{
	event.Skip();
	return;
}

GrafNode* aGrafNode = GetSelectedNode();

if ((aGrafNode!=0) && (aGrafNode!=this))
	aGrafNode->ConnectionRequested(*this);

SetSelectedNode(NULL);
m_Parent->Refresh();