glVector direction = absDirection - absGetCenterPoint();
double rx = my_width/2;
double ry = my_hight/2;
double hf = 0.995; // factor to "spoof" the borderpoint to the center

if ((direction.m_x >= (rx-my_radius)) && (direction.m_y > (ry-my_radius)))
{
    glVector edge(rx-my_radius, ry-my_radius);
    edge += absGetCenterPoint();
    glVector diff(absDirection - edge);
    diff = diff.Dir();
    diff *= my_radius;
    return edge + diff;
}
else if ((direction.m_x <= -(rx-my_radius)) && (direction.m_y > (ry-my_radius)))
{
    glVector edge(-(rx-my_radius), ry-my_radius);
    edge += absGetCenterPoint();
    glVector diff(absDirection - edge);
    diff = diff.Dir();
    diff *= my_radius;
    return edge + diff;
}
else if ((direction.m_x >= rx-my_radius) && (direction.m_y < -(ry-my_radius)))
{
    glVector edge(rx-my_radius, -(ry-my_radius));
    edge += absGetCenterPoint();
    glVector diff(absDirection - edge);
    diff = diff.Dir();
    diff *= my_radius;
    return edge + diff;
}
else if ((direction.m_x <= -(rx-my_radius)) && (direction.m_y < -(ry-my_radius)))
{
    glVector edge(-(rx-my_radius), -(ry-my_radius));
    edge += absGetCenterPoint();
    glVector diff(absDirection - edge);
    diff = diff.Dir();
    diff *= my_radius;
    return edge + diff;
}
else if (direction.m_x >= rx)
    return absGetCenterPoint() +  glVector(hf*rx, hf*direction.m_y);
else if (direction.m_x <= -rx)
    return absGetCenterPoint() +  glVector(hf*-rx, hf*direction.m_y);
else if (direction.m_y >= ry)
    return absGetCenterPoint() +  glVector(hf*direction.m_x, hf*ry);
else if (direction.m_y <= -ry)
    return absGetCenterPoint() +  glVector(hf*direction.m_x, hf*-ry);

if (direction.m_x == 0)
{
    if (direction.m_y >= 0)
        return absGetCenterPoint() +  glVector(0, hf*ry);
    else
        return absGetCenterPoint() +  glVector(0, hf*-ry);
}

double m = abs(direction.m_y / direction.m_x);
double mym = my_hight / my_width;

if (m >= mym)
{
    if (direction.m_y >= 0)
        return absGetCenterPoint() +  glVector(hf*direction.m_x, hf*ry);
    else
        return absGetCenterPoint() +  glVector(hf*direction.m_x, hf*-ry);
}
else
{
    if (direction.m_x >= 0)
        return absGetCenterPoint() +  glVector(hf*rx, hf*direction.m_y);
    else
        return absGetCenterPoint() +  glVector(hf*-rx, hf*direction.m_y);
}

return absGetCenterPoint() +  direction.Dir();
