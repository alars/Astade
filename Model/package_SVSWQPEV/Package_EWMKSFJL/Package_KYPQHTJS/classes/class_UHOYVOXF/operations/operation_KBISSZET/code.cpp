glVector diff = absDrawPosition - absPosition;

if (diff.Mod() > 0.5)
{
	AreaRefresh();
	absDrawPosition = absPosition;
	AreaRefresh();
}