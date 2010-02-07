std::map<glArea *, glVector>::iterator it = nearAreaPoints.find(anArea);

if (it == nearAreaPoints.end())
{
	nearAreaPoints[anArea] = absGetBorderPoint(anArea->absGetCenterPoint()) - absGetCenterPoint();
	it = nearAreaPoints.find(anArea);
}

return (*it).second + absGetCenterPoint();