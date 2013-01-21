//~~ void registerReadFunction(int (*read_func)(char* page, char** start, off_t off, int count,int* eof, void* data)) [kaProcEntry] ~~
if (me->m_entry)
	me->m_entry->read_proc = read_func;
