//~~ int setRetval(unsigned int aRetVal) [Trace2UML] ~~
char buffer[100];
sprintf(buffer,"%u",aRetVal);
retval = buffer;

return aRetVal;