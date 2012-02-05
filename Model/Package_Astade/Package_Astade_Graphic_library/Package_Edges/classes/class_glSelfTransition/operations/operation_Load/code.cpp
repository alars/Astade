//~~ void Load(wxConfigBase& configObject) [glSelfTransition] ~~

configObject.SetPath(wxS("Label"));
myLabel.Load(configObject);
configObject.SetPath(wxS(".."));
glSelfEdge::Load(configObject);
