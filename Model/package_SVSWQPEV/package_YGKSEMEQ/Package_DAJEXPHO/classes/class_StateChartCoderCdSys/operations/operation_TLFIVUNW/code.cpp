wxCmdLineParser CmdLineParser(argc, const_cast<char**>(argv));
CmdLineParser.AddParam("DIRNAME",wxCMD_LINE_VAL_STRING,wxCMD_LINE_OPTION_MANDATORY);
CmdLineParser.AddParam("TARGETFILE",wxCMD_LINE_VAL_STRING,wxCMD_LINE_OPTION_MANDATORY);

CmdLineParser.SetLogo("StatChartCoder: the \"Statchart coder\"\n" COPYRIGHT);

if (CmdLineParser.Parse() == 0)
{
	if (CmdLineParser.GetParamCount()==2)
	{
		AdeStatechart theStatechart(CmdLineParser.GetParam(0));

		if ((theStatechart.GetType()&0x7f00000)!=ITEM_IS_STATECHART)
		{
			printf("Error: only state charts please!");
			return EXIT_FAILURE;
		}

        wxFileName theFileName = CmdLineParser.GetParam(1) ;
	    
	    theFileName.SetExt("c");
	    theFileName.SetName(theStatechart.GetName().Lower() + "_sm");
	    implementationFile = fopen(theFileName.GetFullPath().c_str(),"w");
  	    if (implementationFile == NULL)
	    {
// 		printf("Error: could not open Implementation File. Err: %s", strerror(errno));
		printf("Error: could not open Implementation File.");
		return EXIT_FAILURE;
	    }

	    fprintf(implementationFile,"//******************************************************\n");
	    fprintf(implementationFile,"//** Coding is done with Astade Statechart coder      **\n");
	    fprintf(implementationFile,"//** Filename: %-39s**\n",theFileName.GetFullName().c_str());
	    fprintf(implementationFile,"//******************************************************\n\n");

	    theFileName.SetExt("h");
	    specificationFile = fopen(theFileName.GetFullPath().c_str(),"w");
	    
	    if (specificationFile == NULL)
	    {
		printf("Error: could not open Specification File.");
// 		printf("Error: could not open Specification File. Err: %s", strerror(errno));
		return EXIT_FAILURE;
	    }

	    fprintf(specificationFile,"//******************************************************\n");
	    fprintf(specificationFile,"//** Coding is done with Astade Statechart coder      **\n");
	    fprintf(specificationFile,"//** Filename: %-39s**\n",theFileName.GetFullName().c_str());
	    fprintf(specificationFile,"//******************************************************\n\n");

		fprintf(specificationFile,"/*! \\file %s\n", theFileName.GetFullName().c_str());
		fprintf(specificationFile,"    \\brief %s \n", theStatechart.GetDescription().c_str());
		fprintf(specificationFile,"*/\n\n");

	    theFileName.SetName(theStatechart.GetName().Lower() + "_impl");
	    theFileName.SetExt("h");
	    specificationUsrFile = fopen(theFileName.GetFullPath().c_str(),"w");

  	    if (specificationUsrFile == NULL)
	    {
// 		printf("Error: could not open Specification Usr File. Err: %s", strerror(errno));
		printf("Error: could not open Specification Usr File.");
		return EXIT_FAILURE;
	    }

	    fprintf(specificationUsrFile,"//******************************************************\n");
	    fprintf(specificationUsrFile,"//** Coding is done with Astade Statechart coder      **\n");
	    fprintf(specificationUsrFile,"//** Filename: %-39s**\n",theFileName.GetFullName().c_str());
	    fprintf(specificationUsrFile,"//******************************************************\n\n");

		fprintf(specificationUsrFile,"//!\\file %s\n\n",theFileName.GetFullName().c_str());

		CodeStatechart(theStatechart);

	    fclose(implementationFile);
	    fclose(specificationFile);
	    fclose(specificationUsrFile);

	    theFileName.SetFullName(CmdLineParser.GetParam(1));
	    fclose(fopen(theFileName.GetFullPath().c_str(),"w"));

		return EXIT_SUCCESS;
	}
	else
		return EXIT_FAILURE;
}

return EXIT_FAILURE;
