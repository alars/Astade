//~~ ~Trace2UML() [Trace2UML] ~~
while (sem_wait(&msSemaphore))
    ;

int pid = syscall(SYS_gettid);

if (m_level > tracelevel && ms_ofile.is_open())
{
	const char* flag = NULL;
	switch (m_NotificationType)
	{
		case 2:
			flag = " (X) ";
			break;

		case 1:
			flag = " <== ";
			break;
	}
	if (flag)
	{
		traceTimestamp();
		if (m_PreviousRunningObjectPointer)
			ms_ofile << m_PreviousRunningObjectPointer << ":";
		ms_ofile << m_PreviousRunningObject << flag;

		if (ms_RunningObjectPointer[pid])
			ms_ofile << ms_RunningObjectPointer[pid] << ":";
		ms_ofile << ms_RunningObject[pid] << " " << retval;

		ms_ofile << std::endl;
	}
}

ms_ofile.flush();
ms_RunningObject[pid] = m_PreviousRunningObject;
ms_RunningObjectPointer[pid] = m_PreviousRunningObjectPointer;
sem_post(&msSemaphore);