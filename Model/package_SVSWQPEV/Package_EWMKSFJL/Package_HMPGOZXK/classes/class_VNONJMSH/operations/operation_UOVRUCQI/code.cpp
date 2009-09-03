glVector startCenter = GetStartNode().absGetPosition();
glVector endCenter = GetEndNode().absGetPosition();

glVector diff = endCenter - startCenter;
glVector halfdiff(diff);
halfdiff *= 0.5;

glVector centerdir = diff.Dir().Rotate90Degree();
centerdir *= sqrt((radius*radius) - halfdiff.Mod2());
return startCenter + halfdiff + centerdir;

