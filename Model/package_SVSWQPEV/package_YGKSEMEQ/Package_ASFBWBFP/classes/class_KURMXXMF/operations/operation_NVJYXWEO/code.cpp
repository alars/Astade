wxImage::AddHandler(new wxPNGHandler);
wxImage::AddHandler(new wxJPEGHandler);

myFrame = new  UseFrame;
SetTopWindow(myFrame);
myFrame->Show(true);

return true;