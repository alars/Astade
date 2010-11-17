//~~ AdeModel(const wxFileName& modelPath) [AdeModel] ~~

myFileName.SetFullName(wxS("ModelNode.ini"));
Reload();
myConfig->Write(wxS("Astade/Type"), GetType());
myConfig->Flush();
