deleteID = GetUniqueID();
pinID = GetUniqueID();
Connect(deleteID, wxEVT_COMMAND_MENU_SELECTED,wxCommandEventHandler(GrafNode::Delete));

m_Parent->AddGrafNode(*this);
m_Parent->NotifyModification();
m_Parent->Refresh();