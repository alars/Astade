int main(int argc, char* const* argv)
{
	if (wxInitialize())
	{
		StateChartCoder Coder;
		return Coder.DoIt(argc, argv);
		wxUninitialize();
	}
	return 0;
}