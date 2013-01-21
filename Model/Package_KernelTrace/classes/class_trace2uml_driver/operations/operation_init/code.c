//~~ int init() [trace2uml_driver] ~~
trace2uml_driver_m_entry = create_proc_entry(trace2uml_driver_NAME, trace2uml_driver_READ_ONLY, NULL);

if (trace2uml_driver_m_entry)
    trace2uml_driver_m_entry->read_proc = trace2uml_driver_readTrace;


/* some debug code */

/*
trace2uml_driver_notify_constructor("test",(void*)1);
trace2uml_driver_notify_constructor("test2",(void*)1);
trace2uml_driver_notify_function_call("test","hallo",(void*)1);
trace2uml_driver_notify_function_call("test2","hallo2",(void*)1);
trace2uml_driver_notify_return();
trace2uml_driver_notify_return();
trace2uml_driver_notify_destructor("test",(void*)1);
trace2uml_driver_notify_destructor("test2",(void*)1);
*/

return 0;