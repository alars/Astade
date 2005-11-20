int main(int argc, char* const* argv)
{
	if (wxInitialize())
	{
		StateChartDrawer Drawer;
		return Drawer.doit(argc, argv);
		wxUninitialize();
	}
	return 0;
}