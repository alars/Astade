int minx, maxx, miny, maxy;

if (absDrawnStartPoint.xCoord() < absDrawnEndPoint.xCoord())
{
	minx = absDrawnStartPoint.xCoord() - 12;
	maxx = absDrawnEndPoint.xCoord() + 24;
}
else
{
	maxx = absDrawnStartPoint.xCoord() + 12;
	minx = absDrawnEndPoint.xCoord() - 24;
}

if (absDrawnStartPoint.yCoord() < absDrawnEndPoint.yCoord())
{
	miny = absDrawnStartPoint.yCoord() - 12;
	maxy = absDrawnEndPoint.yCoord() + 24;
}
else
{
	maxy = absDrawnStartPoint.yCoord() + 12;
	miny = absDrawnEndPoint.yCoord() - 24;
}

RefreshRect(wxRect(minx, miny, (maxx-minx), (maxy-miny)));
