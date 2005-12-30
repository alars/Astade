wxImage::AddHandler( new wxPNGHandler );
wxImage::AddHandler( new wxJPEGHandler );

myFrame = new  SeqFrame;
SetTopWindow(myFrame);
myFrame->Show(TRUE);


return true;