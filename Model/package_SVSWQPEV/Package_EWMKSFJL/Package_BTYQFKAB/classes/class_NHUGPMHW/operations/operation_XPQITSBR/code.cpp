glVector border = absGetPosition() - position;

if ((fabs(border.m_x) <= my_XRadius) && (fabs(border.m_y) <= (my_YRadius-my_edgeRadius)))
	return true;

if ((fabs(border.m_x) <= (my_XRadius-my_edgeRadius)) && (fabs(border.m_y) <= my_YRadius))
	return true;

glVector edge(my_XRadius-my_edgeRadius, my_YRadius-my_edgeRadius);
glVector posborder(fabs(border.m_x), fabs(border.m_y));
posborder -= edge;

return (posborder.Mod() <= my_edgeRadius);
