//~~ wxString SetGUID() [AdeDirectoryElement] ~~

wxString aGUID(GUID());
myConfig->Write(wxS("Astade/GUID"), aGUID);
myConfig->Flush();

return aGUID;
