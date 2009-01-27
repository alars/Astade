glVector absStartPoint = absGetStartPoint();
glVector absEndPoint = absGetEndPoint();

glVector diff;

if (&aNode == &myStartNode)
	diff = absStartPoint - absEndPoint;
else if (&aNode == &myStartNode)
	diff = absEndPoint - absStartPoint;
else return glVector(0,0);

if (diff.Mod() > 100)
	diff *= -1;

glVector diffdir = diff.Dir();

diffdir *= 0.01;

return diffdir;