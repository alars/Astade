//~~ void setRetval(size_t aRetVal) [Trace2UML] ~~
char buffer[100];
sprintf(buffer,"%u",(unsigned)aRetVal);
retval = buffer;

return aRetVal;