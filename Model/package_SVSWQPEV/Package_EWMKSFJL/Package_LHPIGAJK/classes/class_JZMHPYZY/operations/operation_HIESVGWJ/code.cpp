myFrame = CreateFrame();
myFrame->Init();
SetTopWindow(myFrame);
myFrame->Show(TRUE);

if (argc > 1)
	myFrame->Load(argv[1]);

return true;
