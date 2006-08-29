m_PreviousRunningObject = m_RunningObject;
m_RunningObject = objectName;

m_PreviousRunningObjectPointer = m_RunningObjectPointer;
m_RunningObjectPointer = objectPointer;

if (m_PreviousRunningObjectPointer)
	std::cerr << m_PreviousRunningObjectPointer << ":";
std::cerr << m_PreviousRunningObject;

switch (m_NotificationType)
{
	case CALL_CONSTRUCTOR:
		std::cerr << "(!) ";
		break;

	case CALL_NOTIFICATION:
		std::cerr << "==> ";
		break;

	case CALL_EVENTRECEIVE:
		std::cerr << "--> ";
		break;
}

if (m_RunningObjectPointer)
	std::cerr << m_RunningObjectPointer << ":";
std::cerr << m_RunningObject;

if (functionName)
	std::cerr << " " << functionName << "(";
if (parameterList)
	std::cerr << parameterList;
if (functionName)
	std::cerr << ")";

std::cerr << std::endl;
