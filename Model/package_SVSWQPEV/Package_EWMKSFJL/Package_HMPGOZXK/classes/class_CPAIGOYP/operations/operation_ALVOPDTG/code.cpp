int minx, maxx, miny, maxy;

if (absDrawnStartPoint.xCoord() < absDrawnEndPoint.xCoord())
{
	minx = absDrawnStartPoint.xCoord() - 20;
	maxx = absDrawnEndPoint.xCoord() + 40;
}
else
{
	maxx = absDrawnStartPoint.xCoord() + 20;
	minx = absDrawnEndPoint.xCoord() - 40;
}

if (absDrawnStartPoint.yCoord() < absDrawnEndPoint.yCoord())
{
	miny = absDrawnStartPoint.yCoord() - 20;
	maxy = absDrawnEndPoint.yCoord() + 40;
}
else
{
	maxy = absDrawnStartPoint.yCoord() + 20;
	miny = absDrawnEndPoint.yCoord() - 40;
}

RefreshRect(wxRect(minx, miny, (maxx-minx), (maxy-miny)));
