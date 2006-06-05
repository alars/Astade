int w,h;
GetSize(&w,&h);

w /= 2;
h /= 2;

double distX = position.m_x - m_Position.m_x;
double distY = position.m_y - m_Position.m_y;

// Bronstein says:
return ( (((1.0*distX*distX) / (1.0*w*w)) + ((1.0*distY*distY) / (1.0*h*h))) < 1);