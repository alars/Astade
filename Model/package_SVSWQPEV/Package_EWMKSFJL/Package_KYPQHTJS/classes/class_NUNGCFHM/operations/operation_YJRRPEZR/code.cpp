glVector otherBorder = otherArea.absCalculateNearestToArea(this);
glVector myBorder = absCalculateNearestToArea(&otherArea);

glVector direction = (myBorder - otherBorder);
double disance = direction.Mod();

glVector ret = direction.Dir();
ret *= 60.0 / (disance*disance);

return ret;
