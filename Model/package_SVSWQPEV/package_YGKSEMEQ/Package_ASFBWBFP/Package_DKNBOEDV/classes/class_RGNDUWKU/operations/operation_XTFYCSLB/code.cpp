if (static_cast<unsigned int>(event.GetId())==pinID)
	m_Pinned = !m_Pinned;
else
	event.Skip();