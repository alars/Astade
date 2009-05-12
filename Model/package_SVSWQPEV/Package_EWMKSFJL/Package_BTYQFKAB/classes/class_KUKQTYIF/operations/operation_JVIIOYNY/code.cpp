double rx = (my_width/2) -15;
double ry = (my_hight/2) -15;

glVector edge = absGetCenterPoint() + glVector(rx, -ry);
if ((absDirection.m_x <= edge.m_x) || (absDirection.m_y >= edge.m_y))
	return glRectangularGravityArea::absGetBorderPoint(absDirection);
	
glVector diff = (absDirection - edge).Dir();

double f = 15 / (fabs(diff.m_y) + fabs(diff.m_x));
diff *= f;

return edge + diff;
