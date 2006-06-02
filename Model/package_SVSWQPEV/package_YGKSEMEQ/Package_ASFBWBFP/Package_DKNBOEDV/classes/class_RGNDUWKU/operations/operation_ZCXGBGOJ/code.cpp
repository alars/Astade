int width,hight,wWidth,wHight;

GetSize(&width,&hight);
m_Parent->GetSize(&wWidth,&wHight);

for (std::list<GrafNode*>::iterator it = m_Parent->GetGrafNodes().begin(); it != m_Parent->GetGrafNodes().end(); it++)
{
	if ((*it) != this)
	{
		GrafVector dif = m_Position - (*it)->GetPosition();
		double dist = dif.Mod();
		if (dist < m_minDist+0.1)
			m_force += dif.Dir();
		else
			m_force += dif.Dir() / (dist - m_minDist);
	}
}

double right_force = 1;
if ((-m_Position.xCoord()+wWidth-width)>0.1)
	right_force = 1.0/(-m_Position.xCoord()+wWidth-width);

double left_force = -1;
if (m_Position.xCoord()>0.1)
	left_force = -1.0/m_Position.xCoord();

double floor_force = 1;
if ((-m_Position.yCoord()+wHight-hight)>0.1)
	floor_force = 1.0/(-m_Position.yCoord()+wHight-hight);

double top_force = -1;
if (m_Position.yCoord()>0.1)
	top_force = 1.0/-m_Position.yCoord();

m_force += GrafVector(0,-top_force);
m_force += GrafVector(0,-floor_force);
m_force += GrafVector(-right_force,0);
m_force += GrafVector(-left_force,0);

m_speed += (m_force / m_mass);
m_speed *= m_damping;
m_Position += m_speed;