if (location == unknown)
	location = Locate(absDirection);

switch (location)
{
	case nearStart:
		return m_Start;
	break;

	case nearEnd:
		return m_End;
	break;

	default:
		return m_Start + (absDirection - m_Start).ProjectionOn(m_Diff);
	break;
}