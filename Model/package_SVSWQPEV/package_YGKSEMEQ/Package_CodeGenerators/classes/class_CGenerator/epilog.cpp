int main(int argc, char* const* argv)
{
	if (wxInitialize())
	{
		CGenerator gen;
		int rc = gen.doit(argc, argv);
		wxUninitialize();
		return rc;
	}
	return EXIT_FAILURE;
}
