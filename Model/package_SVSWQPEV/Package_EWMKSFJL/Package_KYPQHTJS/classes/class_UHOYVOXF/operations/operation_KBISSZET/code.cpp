glVector diff = absDrawPosition - absPosition;

if (diff.Mod() > 0.5)
{
	FloatingRefresh();
	absDrawPosition = absPosition;
	FloatingRefresh();
}