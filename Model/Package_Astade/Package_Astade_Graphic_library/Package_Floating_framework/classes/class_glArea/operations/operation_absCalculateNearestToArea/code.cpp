glVector help = absCalculateNearestToPoint(anArea->absGetNearestToArea(this));
nearAreaPoints[anArea] = help - absGetCenterPoint();
return help;