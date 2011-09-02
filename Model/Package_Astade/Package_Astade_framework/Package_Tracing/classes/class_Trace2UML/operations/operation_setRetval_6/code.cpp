//~~ long setRetval(long aRetVal) [Trace2UML] ~~

char buffer[24];
sprintf(buffer, "%ld", aRetVal);
retval = buffer;

return aRetVal;
