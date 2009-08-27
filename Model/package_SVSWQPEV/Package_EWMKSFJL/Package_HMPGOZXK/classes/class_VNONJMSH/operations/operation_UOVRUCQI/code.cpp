glVector startCenter = GetStartNode().absGetPosition();
glVector endCenter = GetEndNode().absGetPosition();

glVector diff = endCenter - startCenter;
glVector halfdiff(diff);
halfdiff *= 0.5;

glVector centerdir = diff.Dir().Rotate90Degree();
centerdir *= radius;
return startCenter + halfdiff + centerdir;

