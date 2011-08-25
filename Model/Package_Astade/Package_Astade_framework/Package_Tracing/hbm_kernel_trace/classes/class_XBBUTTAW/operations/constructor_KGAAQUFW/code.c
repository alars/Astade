strncpy(me->m_name,name,MAXPROCNAMESIZE);
me->m_entry = create_proc_entry(me->m_name, mode, me->m_parent);
