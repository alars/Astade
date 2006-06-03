int w,h;
GetSize(&w,&h);

w /= 2;
h /= 2;

int distX = position.x - m_Position.xCoord();
int distY = position.y - m_Position.yCoord();

// Bronstein says:
return ( (((1.0*distX*distX) / (1.0*w*w)) + ((1.0*distY*distY) / (1.0*h*h))) < 1);