glVector center = absCalculateCenterPoint();
glVector centerToPoint = absDirection - center;
glVector testvector = centerToPoint.Rotate90Degree();

if (testvector.ScalarProduct(lastEndPoint) < 0)
{
	if (testvector.ScalarProduct(lastStartPoint) < 0)
	{
		return center + lastEndPoint;
	}
	else
	{
		centerToPoint *= -1;
	}
}
else
{
	if (testvector.ScalarProduct(lastStartPoint) > 0)
	{
		return center + lastStartPoint;
	}
}

centerToPoint = centerToPoint.Dir();
if (width < 0)
	centerToPoint *= -radius();
else
	centerToPoint *= radius();

return center + centerToPoint;

