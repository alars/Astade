wxFileSystem::AddHandler(new wxZipFSHandler);
wxImage::AddHandler(new wxJPEGHandler);
wxImage::AddHandler(new wxPNGHandler);
wxImage::AddHandler(new wxGIFHandler);

wxConfigBase* theConfig = wxConfigBase::Get();
myHelp.AddBook(wxFileName(theConfig->Read("TreeView/Helpfile")));
