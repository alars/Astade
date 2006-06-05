GrafVector direction = directionPoint - m_Position;

if ((direction.m_y < 0.0001) && (direction.m_y > -0.0001))
	return m_Position;

double m = direction.m_x/direction.m_y;

int w,h;
GetSize(&w,&h);
w /= 2;
h /= 2;

if ((m < 0.0001) && (m > -0.0001))
{
	if (direction.m_y < 0)
		return m_Position + GrafVector(0,-h);
	else
		return m_Position + GrafVector(0,h);
}

double a2 = (1.0*w*w);
double b2 = (1.0*h*h);
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

return m_Position + GrafVector(x,y);
