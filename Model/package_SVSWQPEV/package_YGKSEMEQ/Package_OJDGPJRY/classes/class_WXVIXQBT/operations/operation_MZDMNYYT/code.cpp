int w,h;
GetSize(&w,&h);

w /= 2;
h /= 2;

double distX = position.x - myPosition.x;
double distY = position.y - myPosition.y;

// Bronstein says:
return ( (((1.0*distX*distX) / (1.0*w*w)) + ((1.0*distY*distY) / (1.0*h*h))) < 1);