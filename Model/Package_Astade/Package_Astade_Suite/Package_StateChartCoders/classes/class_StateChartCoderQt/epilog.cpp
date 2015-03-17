int main(int argc, char* const* argv)
{
	if (wxInitialize())
	{
		StateChartCoderQt Coder;
		int rc = Coder.DoIt(argc, argv);
		wxUninitialize();
		return rc;
	}
	return EXIT_FAILURE;
}
