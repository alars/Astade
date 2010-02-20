int main(int argc, char* const* argv)
{
	if (wxInitialize())
	{
		StateChartCoderACFp Coder;
		int rc = Coder.DoIt(argc, argv);
		wxUninitialize();
		return rc;
	}
	return EXIT_FAILURE;
}
