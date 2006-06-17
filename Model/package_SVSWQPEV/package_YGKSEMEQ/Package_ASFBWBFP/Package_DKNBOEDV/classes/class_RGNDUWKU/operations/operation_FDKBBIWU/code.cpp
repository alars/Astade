for (std::set<GrafNode*>::const_iterator it = m_Parent->GetGrafNodes().begin(); it != m_Parent->GetGrafNodes().end(); it++)
{
	if ((*it) != this)
	{
		(*it)->NotifyDelete(*this);
	}
}

delete(this);