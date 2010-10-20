//~~ AdeModel(const wxFileName& modelPath) [AdeModel] ~~

myFileName.SetFullName(wxS("ModelNode.ini"));
myConfig->Write(wxS("Astade/Type"), GetType());
myConfig->Flush();
