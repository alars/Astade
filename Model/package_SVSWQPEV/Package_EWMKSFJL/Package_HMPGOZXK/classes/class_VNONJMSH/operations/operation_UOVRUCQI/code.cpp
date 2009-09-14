glVector startCenter = GetStartNode().absGetPosition();
glVector endCenter = GetEndNode().absGetPosition();

glVector diff = endCenter - startCenter;
glVector centerdir = diff.Dir().Rotate90Degree();
glVector halfdiff(diff);
halfdiff *= 0.5;

double d;

if (width<0)
	d = -width - radius();
else
	d = radius() - width;

centerdir *= d;

return startCenter + halfdiff + centerdir;

