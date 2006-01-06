int main(int argc, char* const* argv)
{
	if (wxInitialize())
	{
		CppGenerator gen;
		int rc = gen.doit(argc, argv);
		wxUninitialize();
		return rc;
	}
	return EXIT_FAILURE;
}
