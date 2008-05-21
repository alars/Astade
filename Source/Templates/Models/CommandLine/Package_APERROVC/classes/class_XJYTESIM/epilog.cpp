int main(int argc, char** argv)
{
	int retVal = 0;

	try {
		TCLAP::CmdLine cmd("Astade CommandLine Application", ' ', "1.0");

		TCLAP::SwitchArg testSwitch("t", "test", "Test");
		cmd.add(testSwitch);

		cmd.parse( argc, argv );

		if(testSwitch.getValue())
		{
			cout << "You have used the command line switch '-t, --test' for testing." << endl;
		}
		else
		{
			cmd.getOutput()->usage(cmd);
		}

	} catch(TCLAP::ArgException &e) {
		cerr << "An error occured while parsing the command line." << endl
				  << "Error: '" << e.error() << "'" << endl
				  << "for '" << e.argId() << "'" << endl;
		retVal = -1;
	}

	return 0;
};
