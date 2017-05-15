//~~ Trace2UML(int notificationType, int level, const void* objectPointer, const char* objectName, const char* parameterList = 0, const char* functionName = 0) [Trace2UML] ~~
static bool sem_initialzed = false;

if (!sem_initialzed)
{
    sem_init(&msSemaphore, 0, 1);
    sem_initialzed = true;
}

while (sem_wait(&msSemaphore))
    ;

if (m_level > tracelevel && ms_ofile.is_open())
{
	switch (m_NotificationType)
	{
		case 0:
            traceTimestamp();
            ms_ofile << "+ ";
            if (m_objectPointer)
                ms_ofile << m_objectPointer << ":";
            ms_ofile << m_objectName << std::endl;

            traceTimestamp();
            if (m_objectPointer)
                ms_ofile << m_objectPointer << ":";
            ms_ofile << m_objectName << " ==> ";
            if (m_objectPointer)
                ms_ofile << m_objectPointer << ":";
            ms_ofile << m_objectName << " ctor()" << std::endl;
            ms_ofile.flush();
			break;

		case 1:
           traceTimestamp();
            ms_ofile << "> ";

            if (m_objectPointer)
                ms_ofile << m_objectPointer << ":";
            ms_ofile << m_objectName << " ";
            
            if (functionName)
            {
                ms_ofile << functionName << "(";
                if (parameterList)
                    ms_ofile << parameterList;
                ms_ofile << ")";
            }

            ms_ofile << std::endl;
            ms_ofile.flush();
			break;

		case 2:
            traceTimestamp();
            if (m_objectPointer)
                ms_ofile << m_objectPointer << ":";
            ms_ofile << m_objectName << " ==> ";
            if (m_objectPointer)
                ms_ofile << m_objectPointer << ":";
            ms_ofile << m_objectName << " dtor()" << std::endl;
            ms_ofile.flush();
			break;
            
		case 3:
            traceTimestamp();
            
            if (m_objectPointer)
                ms_ofile << m_objectPointer << ":";
            ms_ofile << m_objectName << " ==> ";

            if (m_objectPointer)
                ms_ofile << m_objectPointer << ":";
            ms_ofile << m_objectName << " ";
            
            if (functionName)
            {
                ms_ofile << functionName << "(";
                if (parameterList)
                    ms_ofile << parameterList;
                ms_ofile << ")";
            }

            ms_ofile << std::endl;
            ms_ofile.flush();
			break;

	}
}
sem_post(&msSemaphore);