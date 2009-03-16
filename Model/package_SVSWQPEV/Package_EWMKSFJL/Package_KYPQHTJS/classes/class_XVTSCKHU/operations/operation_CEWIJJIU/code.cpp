if (((absDrawnStartPoint - absGetStartPoint()).Mod() > 0.5) ||
	((absDrawnEndPoint - absGetEndPoint()).Mod() > 0.5))
{
	Refresh();
	absDrawnStartPoint = absGetStartPoint();
	absDrawnEndPoint = absGetEndPoint();
	Refresh();
}