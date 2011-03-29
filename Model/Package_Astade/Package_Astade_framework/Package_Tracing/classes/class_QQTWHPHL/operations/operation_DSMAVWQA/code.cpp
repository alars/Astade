//~~ int setRetval(int aRetVal) [Trace2UML] ~~
char buffer[100];
sprintf(buffer,"%d",aRetVal);
retval = buffer;

return aRetVal;