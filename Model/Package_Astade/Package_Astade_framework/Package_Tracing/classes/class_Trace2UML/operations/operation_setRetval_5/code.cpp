//~~ unsigned int setRetval(unsigned int aRetVal) [Trace2UML] ~~

char buffer[24];
sprintf(buffer, "%u", aRetVal);
retval = buffer;

return aRetVal;
