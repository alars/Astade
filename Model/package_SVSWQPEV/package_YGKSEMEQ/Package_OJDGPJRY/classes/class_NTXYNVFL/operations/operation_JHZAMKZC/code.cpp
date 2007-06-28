if (m_MouseOverNode)
{
	wxMenu* aMenu = m_MouseOverNode->GetContextMenu();
	if (aMenu)
	{
		PopupMenu(aMenu);
		delete aMenu;
	}
}