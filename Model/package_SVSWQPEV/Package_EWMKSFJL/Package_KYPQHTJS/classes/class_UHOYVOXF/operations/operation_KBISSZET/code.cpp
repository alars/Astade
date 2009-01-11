bool doRefresh = ((absDrawPosition.xCoord() != absPosition.xCoord()) || (absDrawPosition.yCoord() != absPosition.yCoord()));

if (doRefresh)
	AreaRefresh();

absDrawPosition = absPosition;

if (doRefresh)
	AreaRefresh();