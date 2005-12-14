wxFileSystem::AddHandler(new wxZipFSHandler);
wxImage::AddHandler(new wxJPEGHandler);
wxImage::AddHandler(new wxPNGHandler);
wxImage::AddHandler(new wxGIFHandler);

wxConfigBase* theConfig = wxConfigBase::Get();
wxString aBook;
if (theConfig->Read("TreeView/Helpfile", &aBook))
	myHelp.AddBook(aBook);
if (theConfig->Read("TreeView/wxHelpfile", &aBook))
	myHelp.AddBook(aBook);
