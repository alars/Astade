glVector sum;

for (std::map<glArea*, glVector>::const_iterator it = startPointForces.begin(); it != startPointForces.end(); it++)
{
    sum += (*it).second;
}

return sum;
