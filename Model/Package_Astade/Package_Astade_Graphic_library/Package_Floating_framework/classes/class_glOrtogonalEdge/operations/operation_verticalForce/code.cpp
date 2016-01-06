//~~ glVector verticalForce() [glOrtogonalEdge] ~~
glVector diff = (GetEndNode().absGetPosition() - GetStartNode().absGetPosition()).Dir();

double a = fabs(diff.m_x) * fabs(diff.m_y);
const double f = 0.05;

double force;

if (a <= f)
    force = a / f;
else
    force = f / a;

if (fabs(diff.m_x) > fabs(diff.m_y))
{
    return glVector(0,14*force * diff.m_y);
}
else
{
   return glVector(14*force * diff.m_x,0);
}