if (m_PreviousRunningObjectPointer)
	std::cerr << m_PreviousRunningObjectPointer << ":";
std::cerr << m_PreviousRunningObject;

switch (m_NotificationType)
{
	case CALL_DESTRUCTOR:
		std::cerr << "(X) ";
		break;

	case CALL_NOTIFICATION:
		std::cerr << "<== ";
		break;
}

if (m_RunningObjectPointer)
	std::cerr << m_RunningObjectPointer << ":";
std::cerr << m_RunningObject;

if (m_ReturnString)
	std::cerr << " " << m_ReturnString;

std::cerr << std::endl;

m_RunningObject = m_PreviousRunningObject;
m_RunningObjectPointer = m_PreviousRunningObjectPointer;
