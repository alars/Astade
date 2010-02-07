wxCmdLineParser CmdLineParser(argc, const_cast<char**>(argv));
CmdLineParser.AddParam("DIRNAME",wxCMD_LINE_VAL_STRING,wxCMD_LINE_OPTION_MANDATORY);

CmdLineParser.SetLogo("StatChartDrawer: the \"Statchart drawer\"\n" COPYRIGHT);

if (CmdLineParser.Parse() == 0)
{
	if (CmdLineParser.GetParamCount() == 1)
	{
		AdeStatechart theElement(CmdLineParser.GetParam(0));

		if ((theElement.GetType() & ITEM_TYPE_MASK) != ITEM_IS_STATECHART)
		{
			printf("Error: only State charts please!");
			return EXIT_FAILURE;
		}

		drawStatechart(theElement, stdout);

		return EXIT_SUCCESS;
	}
	else
		return EXIT_FAILURE;
}

return EXIT_FAILURE;
