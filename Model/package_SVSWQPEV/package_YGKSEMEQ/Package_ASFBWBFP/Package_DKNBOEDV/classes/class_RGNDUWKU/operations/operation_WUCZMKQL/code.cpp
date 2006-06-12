lastMouseEvent = event.GetPosition();
myLabel->Hide();

event.Skip();

if (!IsInArea(lastMouseEvent))
	return;

myLabel->Show();
myLabel->SetFocus();

SetSelectedNode(NULL);
m_Parent->Refresh();