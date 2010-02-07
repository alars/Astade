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

double diffMod = diff.Mod();

if (diffMod <= glFloatingConstants::minRoundEdgeLen)
	return glVector(0,0) - endForce;

glVector diffdir = diff.Dir();

diffdir *= (diffMod - glFloatingConstants::minRoundEdgeLen);

diffdir *= glFloatingConstants::roundEdgeElasticity;

return diffdir - endForce;
