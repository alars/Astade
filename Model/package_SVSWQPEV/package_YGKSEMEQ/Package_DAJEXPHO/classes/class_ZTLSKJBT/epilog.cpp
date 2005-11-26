int main(int argc, char* const* argv)
{
	if (wxInitialize())
	{
		StateChartCoder Coder;
		return Coder.doit(argc, argv);
		wxUninitialize();
	}
	return 0;
}