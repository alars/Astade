int width,hight,wWidth,wHight;

for (std::list<GrafNode*>::const_iterator it = m_Parent->GetGrafNodes().begin(); it != m_Parent->GetGrafNodes().end(); it++)
{
	if ((*it) != this)
	{
		GrafVector r1 = (*it)->GetBorderPoint(GetPosition());
		GrafVector r2 = GetBorderPoint((*it)->GetPosition());

		GrafVector dif = r2-r1;
		double dist = dif.Mod();
		GrafVector resultingForce;

		if (IsInArea(r1))
			resultingForce -= dif.Dir();
		else
			resultingForce = dif.Dir() / (dist);

		if (resultingForce.Mod()>3)
			resultingForce = resultingForce.Dir();

		m_force += resultingForce;
		(*it)->m_force -= resultingForce;
	}
}

GetSize(&width,&hight);
m_Parent->GetSize(&wWidth,&wHight);

width /= 2;
hight /= 2;

double right_force = 1;
if ((-m_Position.xCoord()+wWidth-width)>0.1)
	right_force = 1.0/(-m_Position.xCoord()+wWidth-width);

double left_force = -1;
if ((m_Position.xCoord()-width)>0.1)
	left_force = -1.0/(m_Position.xCoord()-width);

double floor_force = 1;
if ((-m_Position.yCoord()+wHight-hight)>0.1)
	floor_force = 1.0/(-m_Position.yCoord()+wHight-hight);

double top_force = -1;
if ((m_Position.yCoord()-hight)>0.1)
	top_force = 1.0/-(m_Position.yCoord()-hight);

m_force += GrafVector(0,-top_force);
m_force += GrafVector(0,-floor_force);
m_force += GrafVector(-right_force,0);
m_force += GrafVector(-left_force,0);

if (m_MouseOver)
{
	m_speed = GrafVector();
	return 0;
}

m_speed += (m_force / m_mass);
m_speed *= m_damping;
m_Position += m_speed;
return m_speed.Mod();