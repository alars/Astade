//~~ void Save(wxConfigBase& configObject) [glSelfTransition] ~~

configObject.SetPath(wxS("Label"));
myLabel.Save(configObject);
configObject.SetPath(wxS(".."));
glSelfEdge::Save(configObject);
