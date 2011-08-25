//~~ void exit_module() [trcDriver] ~~
kaProcEntry_Destructor(&trcDriver_sm_trace);
remove_proc_entry("driver/trace2uml",NULL);
