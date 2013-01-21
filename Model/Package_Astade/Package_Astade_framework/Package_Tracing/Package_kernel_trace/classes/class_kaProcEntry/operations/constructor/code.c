//~~ kaProcEntry(const char* name, mode_t mode, struct proc_dir_entry* parent) [kaProcEntry] ~~
strncpy(me->m_name,name,MAXPROCNAMESIZE);
me->m_entry = create_proc_entry(me->m_name, mode, me->m_parent);
