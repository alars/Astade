//~~ int readTrace(char* page, char** start, off_t off, int count, int* eof, void* data) [trcDriver] ~~
int done = 0;
char* line = page;
int readfrom;

*page = 0;

readfrom = off & 0xfff;

while (1)
{

	if (readfrom == trcDriver_nextWrite)
	{
		set_current_state(TASK_INTERRUPTIBLE);
		if  (schedule_timeout(2))
		{
			*eof = 1;	
			return(0);
		}
	}
	
	if (readfrom != trcDriver_nextWrite)
	{
		while((readfrom != trcDriver_nextWrite) && ((200 + (line - page)) < count))
		{
			if (trcDriver_mytrcEntries[readfrom].callerID)
			{
				line = line + sprintf(line,"%p:", trcDriver_mytrcEntries[readfrom].callerID);
			}

			switch (trcDriver_mytrcEntries[readfrom].type)
			{
				case FUNCTIONCALL:
					if (trcDriver_mytrcEntries[readfrom].calledID)
						line = line + sprintf(line,"%s ==> %p:%s %s()\n",
							trcDriver_mytrcEntries[readfrom].callerName,
							trcDriver_mytrcEntries[readfrom].calledID,
							trcDriver_mytrcEntries[readfrom].calledName,
							trcDriver_mytrcEntries[readfrom].calledFunction
							);
					else
						line = line + sprintf(line,"%s ==> %s %s()\n",
							trcDriver_mytrcEntries[readfrom].callerName,
							trcDriver_mytrcEntries[readfrom].calledName,
							trcDriver_mytrcEntries[readfrom].calledFunction
							);
				break;
				case FUNCTIONRETURN:
					if (trcDriver_mytrcEntries[readfrom].calledID)
						line = line + sprintf(line,"%s <== %p:%s\n",
							trcDriver_mytrcEntries[readfrom].callerName,
							trcDriver_mytrcEntries[readfrom].calledID,
							trcDriver_mytrcEntries[readfrom].calledName
							);
					else
						line = line + sprintf(line,"%s <== %s\n",
							trcDriver_mytrcEntries[readfrom].callerName,
							trcDriver_mytrcEntries[readfrom].calledName
							);
				break;
				case CONSTRUCTOR:
					line = line + sprintf(line,"%s (!) %p:%s\n",
						trcDriver_mytrcEntries[readfrom].callerName,
						trcDriver_mytrcEntries[readfrom].calledID,
						trcDriver_mytrcEntries[readfrom].calledName
						);
				break;
				case DESTRUCTOR:
					line = line + sprintf(line,"%s (X) %p:%s\n",
						trcDriver_mytrcEntries[readfrom].callerName,
						trcDriver_mytrcEntries[readfrom].calledID,
						trcDriver_mytrcEntries[readfrom].calledName
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
