glVector absStartPoint = absGetStartPoint();
glVector absEndPoint = absGetEndPoint();

glVector diff;
glVector endForce;

if (&aNode == &myEndNode)
{
	diff = absStartPoint - absEndPoint;
	endForce = getEndPointForce();
}
else if (&aNode == &myStartNode)
{
	diff = absEndPoint - absStartPoint;
	endForce = getStartPointForce();
}
else return glVector(0,0);

const int normLen = 50;

if (diff.Mod() <= normLen)
	return endForce;

glVector diffdir = diff.Dir();

diffdir *= (diff.Mod() - normLen);

diffdir *= 0.00003;

return diffdir - endForce;
