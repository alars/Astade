deleteID = GetUniqueID();
Connect(deleteID, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GrafNode::Delete));

m_Parent->AddGrafNode(*this);
m_Parent->Refresh();