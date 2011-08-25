if (me->m_entry)
	remove_proc_entry(me->m_name, me->m_parent);
me->m_entry = NULL;
