glVector startCenter = GetStartNode().absGetPosition();
glVector endCenter = GetEndNode().absGetPosition();

glVector diff = endCenter - startCenter;
diff *= 0.5;

double ret = (diff.Mod2()/(2*width) + (width/2));

if (ret < 0)
	ret *= -1;

return ret;
