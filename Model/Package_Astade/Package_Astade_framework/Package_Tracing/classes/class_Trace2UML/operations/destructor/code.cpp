//~~ ~Trace2UML() [Trace2UML] ~~
while (sem_wait(&msSemaphore))
    ;

if (m_level > tracelevel && ms_ofile.is_open())
{
	switch (m_NotificationType)
	{
		case 1:
		case 3:
        case 0:
    		traceTimestamp();
            ms_ofile << "<" << std::endl;
            ms_ofile.flush();
           break;
            
		case 2:
    		traceTimestamp();
            ms_ofile << "<" << std::endl;

            traceTimestamp();
            ms_ofile << "- ";

            if (m_objectPointer)
                ms_ofile << m_objectPointer << ":";
            ms_ofile << m_objectName << std::endl;

            ms_ofile.flush();
			break;
    }

}
sem_post(&msSemaphore);