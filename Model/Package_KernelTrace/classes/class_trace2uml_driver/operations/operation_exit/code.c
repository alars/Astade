//~~ void exit() [trace2uml_driver] ~~
if (trace2uml_driver_m_entry)
	remove_proc_entry(trace2uml_driver_NAME, NULL);
trace2uml_driver_m_entry = NULL;
