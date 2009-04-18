glVector direction = absDirection - absGetCenterPoint();
double rx = my_width/2;
double ry = my_hight/2;

if ((direction.m_x >= rx) && (direction.m_y >= ry))
    return absGetCenterPoint() +  glVector(rx, ry);
else if ((direction.m_x <= -rx) && (direction.m_y >= ry))
    return absGetCenterPoint() +  glVector(-rx, ry);
else if ((direction.m_x >= rx) && (direction.m_y <= -ry))
    return absGetCenterPoint() +  glVector(rx, -ry);
else if ((direction.m_x <= -rx) && (direction.m_y <= -ry))
    return absGetCenterPoint() +  glVector(-rx, -ry);
else if (direction.m_x >= rx)
    return absGetCenterPoint() +  glVector(rx, direction.m_y);
else if (direction.m_x <= -rx)
    return absGetCenterPoint() +  glVector(-rx, direction.m_y);
else if (direction.m_y >= ry)
    return absGetCenterPoint() +  glVector(direction.m_x, ry);
else if (direction.m_y <= -ry)
    return absGetCenterPoint() +  glVector(direction.m_x, -ry);

return absGetCenterPoint() +  direction.Dir();
