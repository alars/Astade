//~~ Trace2UML(int notificationType, int level, const void* objectPointer, const char* objectName, const char* parameterList = 0, const char* functionName = 0) [Trace2UML] ~~
static bool sem_initialzed = false;

if (!sem_initialzed)
{
    sem_init(&msSemaphore, 0, 1);
    sem_initialzed = true;
}

while (sem_wait(&msSemaphore))
    ;

int pid = syscall(SYS_gettid);

if (ms_RunningObject[pid] == 0)
    ms_RunningObject[pid] = "*";

m_PreviousRunningObject = ms_RunningObject[pid];
ms_RunningObject[pid] = objectName;

m_PreviousRunningObjectPointer = ms_RunningObjectPointer[pid];
ms_RunningObjectPointer[pid] = objectPointer;

if (m_level > tracelevel && ms_ofile.is_open())
{
	const char* flag = NULL;
	switch (m_NotificationType)
	{
		case 0:
			flag = " (!) ";
			break;

		case 1:
		case 3:
			flag = " ==> ";
			break;

	}
	if (flag)
	{
		traceTimestamp();
        if (m_NotificationType == 3)
        {
            if (ms_RunningObjectPointer[pid])
                ms_ofile << ms_RunningObjectPointer[pid] << ":";
            ms_ofile << ms_RunningObject[pid] << flag;
        }
        else
        {
            if (m_PreviousRunningObjectPointer)
                ms_ofile << m_PreviousRunningObjectPointer << ":";
            ms_ofile << m_PreviousRunningObject << flag;
        }

        if (ms_RunningObjectPointer[pid])
            ms_ofile << ms_RunningObjectPointer[pid] << ":";
        ms_ofile << ms_RunningObject[pid] << " ";
        
		if (functionName)
			ms_ofile << functionName << "(";
		if (parameterList)
			ms_ofile << parameterList;
		if (functionName)
			ms_ofile << ")";

		ms_ofile << std::endl;
	}
}
ms_ofile.flush();
sem_post(&msSemaphore);