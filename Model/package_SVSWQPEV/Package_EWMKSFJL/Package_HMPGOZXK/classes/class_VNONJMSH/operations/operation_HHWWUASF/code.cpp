glSegment aSegment(absGetStartPoint(), absGetEndPoint());
glSegment::position aPosition = aSegment.Locate(absDirection);

switch (aPosition)
{
	case glSegment::nearStart:
		return aSegment.m_Start;
	break;

	case glSegment::nearEnd:
		return aSegment.m_End;
	break;

	default:
		glVector center = absCalculateCenterPoint();
		glVector ret = (absDirection - center).Dir();
		ret *= radius();
		return ret + center;
	break;
}

return aSegment.m_Start;

