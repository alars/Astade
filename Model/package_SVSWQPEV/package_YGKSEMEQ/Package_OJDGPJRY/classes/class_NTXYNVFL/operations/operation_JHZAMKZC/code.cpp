if (m_MouseOverNode)
{
	wxMenu* aMenu = m_MouseOverNode->GetContextMenu();
	if (aMenu)
	{
		m_MenuNode = m_MouseOverNode;
		PopupMenu(aMenu);
		delete aMenu;
		m_MouseOverNode = NULL;
	}
}