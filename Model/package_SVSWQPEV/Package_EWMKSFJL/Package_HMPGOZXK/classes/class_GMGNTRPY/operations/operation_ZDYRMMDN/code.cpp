glVector absStartPoint = absGetStartPoint();
glVector absEndPoint = absGetEndPoint();

glVector diff;

if (&aNode == &myEndNode)
	diff = absStartPoint - absEndPoint;
else if (&aNode == &myStartNode)
	diff = absEndPoint - absStartPoint;
else return glVector(0,0);

const int normLen = 100;

if (diff.Mod() <= normLen)
	return glVector(0,0);

glVector diffdir = diff.Dir();

diffdir *= (diff.Mod() - normLen);

diffdir *= 0.00001;

return diffdir;