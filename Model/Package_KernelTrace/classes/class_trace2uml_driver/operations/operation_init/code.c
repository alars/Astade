//~~ int init() [trace2uml_driver] ~~
trace2uml_driver_m_entry = create_proc_entry(trace2uml_driver_NAME, trace2uml_driver_READ_ONLY, NULL);

/* some debug code */

trace2uml_driver_notify_function_call("test","hallo",NULL);
trace2uml_driver_notify_function_call("test2","hallo2",NULL);
trace2uml_driver_notify_function_call("test3","hallo3",NULL);

/* */

return 0;