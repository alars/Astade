//~~ void notify_constructor(char* objectName, void* objectID) [trace2uml_driver] ~~
trace2uml_driver_buffer[trace2uml_driver_nextWrite].type = CONSTRUCTOR;
trace2uml_driver_buffer[trace2uml_driver_nextWrite].calledID = objectID;
trace2uml_driver_buffer[trace2uml_driver_nextWrite++].calledName = objectName;

trace2uml_driver_nextWrite &= 0xfff;
