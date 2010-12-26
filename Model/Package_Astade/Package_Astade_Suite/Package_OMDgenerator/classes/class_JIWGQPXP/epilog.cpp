int main(int argc, char* const* argv)
{
	if (wxInitialize())
	{
		CSDgenerator csd;
		int rc = csd.doit(argc, argv);
		wxUninitialize();
		return rc;
	}
	return EXIT_FAILURE;
}
