int width,hight,wWidth,wHight;

GetSize(&width,&hight);
m_Parent->GetSize(&wWidth,&wHight);

double right_force = 1;
if ((-m_Position.xCoord()+wWidth-width)>0)
	right_force = 1.0/(-m_Position.xCoord()+wWidth-width);

double left_force = -1;
if (m_Position.xCoord()>0)
	left_force = 1.0/m_Position.xCoord();

double floor_force = 1;
if ((-m_Position.yCoord()+wHight-hight)>0)
	floor_force = 1.0/(-m_Position.yCoord()+wHight-hight);

double top_force = -1;
if (m_Position.yCoord()>0)
	top_force = 1.0/-m_Position.yCoord();

m_force += GrafVector(0,-top_force);
m_force += GrafVector(0,-floor_force);
m_force += GrafVector(-right_force,0);
m_force += GrafVector(-left_force,0);

m_speed += (m_force / m_mass);
m_speed *= m_damping;
m_Position += m_speed;
Move(m_Position.xCoord(),m_Position.yCoord());