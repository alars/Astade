glVector start = absGetStartPoint();
glVector end = absGetEndPoint();
glVector diff = end - start;

diff *= 0.5;

return start + diff;
