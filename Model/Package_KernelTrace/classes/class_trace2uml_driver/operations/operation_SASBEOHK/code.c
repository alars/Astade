//~~ int readTrace(char* page, char** start, off_t off, int count, int* eof, void* data) [trace2uml_driver] ~~
int done = 0;
char* line = page;
int readfrom;

*page = 0;

readfrom = off & 0xfff;

while (1)
{

    if (readfrom == trace2uml_driver_nextWrite)
    {
        set_current_state(TASK_INTERRUPTIBLE);
        if  (schedule_timeout(2))
        {
            *eof = 1;	
            return(0);
        }
    }
    
    if (readfrom != trace2uml_driver_nextWrite)
    {
        while((readfrom != trace2uml_driver_nextWrite) && ((200 + (line - page)) < count))
        {
            switch (trace2uml_driver_buffer[readfrom].type)
            {
                case FUNCTIONCALL:
                    if (trace2uml_driver_buffer[readfrom].calledID)
                        line = line + sprintf(line,">%p:%s %s()\n",
                            trace2uml_driver_buffer[readfrom].calledID,
                            trace2uml_driver_buffer[readfrom].calledName,
                            trace2uml_driver_buffer[readfrom].calledFunction
                            );
                    else
                        line = line + sprintf(line,">%s %s()\n",
                            trace2uml_driver_buffer[readfrom].calledName,
                            trace2uml_driver_buffer[readfrom].calledFunction
                            );
                break;
                case FUNCTIONRETURN:
                    line = line + sprintf(line,"<\n"
                        );
                break;
                case CONSTRUCTOR:
                    if (trace2uml_driver_buffer[readfrom].calledID)
                        line = line + sprintf(line,"+%p:%s\n",
                            trace2uml_driver_buffer[readfrom].calledID,
                            trace2uml_driver_buffer[readfrom].calledName
                            );
                    else
                        line = line + sprintf(line,"+%s\n",
                            trace2uml_driver_buffer[readfrom].calledName
                            );
                break;
                case DESTRUCTOR:
                    if (trace2uml_driver_buffer[readfrom].calledID)
                        line = line + sprintf(line,"-%p:%s\n",
                            trace2uml_driver_buffer[readfrom].calledID,
                            trace2uml_driver_buffer[readfrom].calledName
                            );
                    else
                        line = line + sprintf(line,"-%s\n",
                            trace2uml_driver_buffer[readfrom].calledName
                            );
                break;
            }

            done++;
            readfrom++;
        }	 

        *start = (char*)done;
        *eof = 1;
        return(line - page);
    }
}

return(0);
