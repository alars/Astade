int main(int argc, char* const* argv)
{
	if (wxInitialize())
	{
		OMDgenerator omd;
		int rc = omd.doit(argc, argv);
		wxUninitialize();
		return rc;
	}
	return EXIT_FAILURE;
}
