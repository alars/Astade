int minx, maxx, miny, maxy;

if (absDrawnStartPoint.xCoord() < absDrawnEndPoint.xCoord())
{
	minx = absDrawnStartPoint.xCoord() - 10;
	maxx = absDrawnEndPoint.xCoord() + 20;
}
else
{
	maxx = absDrawnStartPoint.xCoord() + 10;
	minx = absDrawnEndPoint.xCoord() - 20;
}

if (absDrawnStartPoint.yCoord() < absDrawnEndPoint.yCoord())
{
	miny = absDrawnStartPoint.yCoord() - 10;
	maxy = absDrawnEndPoint.yCoord() + 20;
}
else
{
	maxy = absDrawnStartPoint.yCoord() + 10;
	miny = absDrawnEndPoint.yCoord() - 20;
}

RefreshRect(wxRect(minx, miny, (maxx-minx), (maxy-miny)));
