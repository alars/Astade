wxCmdLineParser CmdLineParser(argc, const_cast<char**>(argv));
CmdLineParser.AddParam("DIRNAME",wxCMD_LINE_VAL_STRING,wxCMD_LINE_OPTION_MANDATORY);
CmdLineParser.AddParam("TARGETFILE",wxCMD_LINE_VAL_STRING,wxCMD_LINE_OPTION_MANDATORY);

CmdLineParser.SetLogo("StatChartCoder: the \"Statchart coder\"\n" COPYRIGHT);

if (CmdLineParser.Parse() == 0)
{
	if (CmdLineParser.GetParamCount()==2)
	{
		AdeStatechart theElement(CmdLineParser.GetParam(0));

		if ((theElement.GetType()&0x7f00000)!=ITEM_IS_STATECHART)
		{
			printf("Error: only state charts please!");
			return EXIT_FAILURE;
		}

        wxFileName theFileName = CmdLineParser.GetParam(1);
	    theFileName.SetExt("cpp");
	    implementationFile = fopen(theFileName.GetFullPath().c_str(),"w");

	    fprintf(implementationFile,"//******************************************************\n");
	    fprintf(implementationFile,"//** Coding is done with Astade Statechart coder      **\n");
	    fprintf(implementationFile,"//** (Special Version for VirtualStateMachine.cpp)    **\n");
	    fprintf(implementationFile,"//** Filename: %-39s**\n",theFileName.GetFullName().c_str());
	    fprintf(implementationFile,"//******************************************************\n\n");

	    theFileName.SetExt("h");
	    specificationFile = fopen(theFileName.GetFullPath().c_str(),"w");

	    fprintf(specificationFile,"//******************************************************\n");
	    fprintf(specificationFile,"//** Coding is done with Astade Statechart coder      **\n");
	    fprintf(specificationFile,"//** (Special Version for VirtualStateMachine.cpp)    **\n");
	    fprintf(specificationFile,"//** Filename: %-39s**\n",theFileName.GetFullName().c_str());
	    fprintf(specificationFile,"//******************************************************\n\n");

		fprintf(specificationFile,"//!\\file %s\n\n",theFileName.GetFullName().c_str());

		CodeStatechart(theElement);

	    fclose(implementationFile);
	    fclose(specificationFile);

		return EXIT_SUCCESS;
	}
	else
		return EXIT_FAILURE;
}

return EXIT_FAILURE;
