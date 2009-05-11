glVector diff = (GetEndNode().absGetPosition() - GetStartNode().absGetPosition()).Dir();

double m;
if (fabs(diff.m_y) < 0.0001)
    m = 3;
else
    m = diff.m_x / diff.m_y;

if ( fabs(m) <= 2)
{
    double force = 0.2 * diff.m_x;
    return glVector(force,0);
}
else
{
    double force = 0.2 * diff.m_y;
    return glVector(0,force);
}
