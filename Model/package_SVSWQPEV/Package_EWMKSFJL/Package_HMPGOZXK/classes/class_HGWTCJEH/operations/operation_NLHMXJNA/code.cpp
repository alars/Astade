glVector start = absGetStartPoint();
glVector end = absGetEndPoint();
glVector diff = end - start;

diff *= 0.5;

glVector widthVector = (diff.Rotate90Degree()).Dir();
widthVector *= -width;

return start + diff + widthVector;

