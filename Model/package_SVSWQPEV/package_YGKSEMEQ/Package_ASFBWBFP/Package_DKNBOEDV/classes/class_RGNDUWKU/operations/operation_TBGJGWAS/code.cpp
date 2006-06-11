lastMouseEvent = event.GetPosition();
myLabel->Hide();

event.Skip();

if (!IsInArea(lastMouseEvent))
	return;

GrafNode* aGrafNode = GetSelectedNode();

if ((aGrafNode!=0) && (aGrafNode!=this))
	aGrafNode->ConnectionRequested(*this);
else
{
	myLabel->Show();
	myLabel->SetFocus();
}

SetSelectedNode(NULL);
m_Parent->Refresh();