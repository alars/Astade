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

if (direction.m_x == 0)
{
    if (direction.m_y >= 0)
        return absGetCenterPoint() +  glVector(0, ry);
    else
        return absGetCenterPoint() +  glVector(0, -ry);
}

double m = abs(direction.m_y / direction.m_x);
double mym = my_hight / my_width;

if (m >= mym)
{
    if (direction.m_y >= 0)
        return absGetCenterPoint() +  glVector(direction.m_x, ry);
    else
        return absGetCenterPoint() +  glVector(direction.m_x, -ry);
}
else
{
    if (direction.m_x >= 0)
        return absGetCenterPoint() +  glVector(rx, direction.m_y);
    else
        return absGetCenterPoint() +  glVector(-rx, direction.m_y);
}

return absGetCenterPoint() +  direction.Dir();
