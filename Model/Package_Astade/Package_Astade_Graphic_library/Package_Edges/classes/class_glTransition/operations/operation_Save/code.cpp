//~~ void Save(wxConfigBase& configObject) [glTransition] ~~

configObject.SetPath(wxS("Label"));
myLabel.Save(configObject);
configObject.SetPath(wxS(".."));
