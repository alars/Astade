glVector startToPoint = aVector-m_Start;

if (startToPoint.ScalarProduct(m_Diff) <= 0)
	return nearStart;

glVector endToPoint = aVector-m_End;

if (endToPoint.ScalarProduct(m_Diff) >= 0)
	return nearEnd;

glVector rotated = m_Diff.Rotate90Degree();

if (rotated.ScalarProduct(startToPoint) <= 0)
	return right;

return left;