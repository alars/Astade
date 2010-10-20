//~~ void SetRepository(const wxString& repositoryName) [AdeModel] ~~

myConfig->Write(wxS("Astade/Repository"), repositoryName);
myConfig->Flush();
