glVector startCenter = GetStartNode().absGetPosition();
glVector endCenter = GetEndNode().absGetPosition();

glVector diff = endCenter - startCenter;
glVector centerdir = diff.Dir().Rotate90Degree();
glVector halfdiff(diff);
halfdiff *= 0.5;

double d = radius() - width;

centerdir *= d;

return startCenter + halfdiff + centerdir;
