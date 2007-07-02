if (m_Pinned)
{
	m_speed = GrafVector(0,0);
	m_force = GrafVector(0,0);
	return;
}

int width,hight,wWidth,wHight;

for (std::set<GrafNode*>::const_iterator it = m_Parent->GetGrafNodes().begin(); it != m_Parent->GetGrafNodes().end(); it++)
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
			resultingForce = (dif.Dir() * 60) / (dist * dist);

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
	m_force = m_speed;
	return;
}

m_speed += (m_force / m_mass);
m_speed *= m_damping;
m_Position += m_speed;

myLabel->Move(m_Position.xCoord()+labelOffset.x,m_Position.yCoord()+labelOffset.y);

if ((m_Position-m_DrawPosition).Mod2()>1)
{
	m_DrawPosition = m_Position;
	Refresh();
	m_Parent->RefreshEdge(this);
}

