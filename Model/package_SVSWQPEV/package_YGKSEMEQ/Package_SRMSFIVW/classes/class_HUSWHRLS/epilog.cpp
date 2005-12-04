int main(int argc, char* const* argv)
{
	if (wxInitialize())
	{
		StateChartDrawer Drawer;
		int rc = Drawer.doit(argc, argv);
		wxUninitialize();
		return rc;
	}
	return EXIT_FAILURE;
}
