//~~ unsigned long setRetval(unsigned long aRetVal) [Trace2UML] ~~

char buffer[24];
sprintf(buffer, "%lu", aRetVal);
retval = buffer;

return aRetVal;
