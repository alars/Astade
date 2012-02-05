//~~ void Load(wxConfigBase& configObject) [glTransition] ~~

configObject.SetPath(wxS("Label"));
myLabel.Load(configObject);
configObject.SetPath(wxS(".."));
