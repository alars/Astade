glVector direction = (absDirection - absGetCenterPoint()).Dir();

if ((direction.m_y < 0.0001) && (direction.m_y > -0.0001))
{
    if (direction.m_x > 0)
    	return absGetCenterPoint() +  glVector(my_X_Radius, 0);
    else
    	return absGetCenterPoint() +  glVector(-my_X_Radius, 0);
}

double m = direction.m_x/direction.m_y;

if ((m < 0.0001) && (m > -0.0001))
{
    if (direction.m_y > 0)
	    return absGetCenterPoint() +  glVector(0, my_Y_Radius);
    else
	    return absGetCenterPoint() +  glVector(0, -my_Y_Radius);
}

double a2 = my_X_Radius * my_X_Radius;
double b2 = my_Y_Radius * my_Y_Radius;
double m2 = m*m;

double z1 = 1/a2;
double z2 = 1/(m2*b2);

double x = sqrt(1/(z1+z2));

double y = x/m;

if (direction.m_x < 0)
{
	x *= -1;
	y *= -1;
}

return absGetCenterPoint() +  glVector(x, y);
