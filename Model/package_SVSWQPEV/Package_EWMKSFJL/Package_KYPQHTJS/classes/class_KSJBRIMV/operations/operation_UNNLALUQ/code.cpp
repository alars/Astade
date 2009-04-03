for (std::map<glArea*, glVector>::const_iterator it = nearAreaPoints.begin(); it != nearAreaPoints.end(); it++)
{   
    glVector p((*it).second + absGetCenterPoint());
    dc.DrawCircle(p.xCoord(), p.yCoord(),3);
}
