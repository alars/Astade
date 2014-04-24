wxImage::AddHandler( new wxPNGHandler );
wxImage::AddHandler( new wxJPEGHandler );

myFrame = new  SeqFrame;
SetTopWindow(myFrame);
myFrame->Show(TRUE);

if (argc > 1)
	myFrame->Load(argv[1]);

return true;