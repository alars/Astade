wxImage::AddHandler(new wxPNGHandler);
wxImage::AddHandler(new wxJPEGHandler);

myFrame = new  UseFrame;
SetTopWindow(myFrame);
myFrame->Show(true);

if (argc > 1)
	myFrame->Load(argv[1]);

return true;