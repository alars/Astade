wxFileSystem::AddHandler(new wxZipFSHandler);
wxImage::AddHandler(new wxJPEGHandler);
wxImage::AddHandler(new wxPNGHandler);
wxImage::AddHandler(new wxGIFHandler);
myHelp = new wxHtmlHelpController;
myHelp->AddBook(wxFileName("help.zip"));
