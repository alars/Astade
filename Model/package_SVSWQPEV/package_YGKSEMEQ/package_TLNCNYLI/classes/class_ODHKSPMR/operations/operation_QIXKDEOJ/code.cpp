		wxFileSystem::AddHandler(new wxZipFSHandler);

wxConfigBase* theConfig = wxConfigBase::Get();
wxString aBook;
if (theConfig->Read("TreeView/Helpfile", &aBook))
	myHelp.AddBook(aBook);
