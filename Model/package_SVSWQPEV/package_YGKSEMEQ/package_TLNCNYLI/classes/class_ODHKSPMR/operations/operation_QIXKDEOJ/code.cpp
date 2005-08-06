wxFileSystem::AddHandler(new wxZipFSHandler);
wxImage::AddHandler(new wxJPEGHandler);
wxImage::AddHandler(new wxPNGHandler);
wxImage::AddHandler(new wxGIFHandler);
myHelp.AddBook(wxFileName("help.zip"));
