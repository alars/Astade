//~~ void Save(wxConfigBase& configObject) [glSelfRelation] ~~

configObject.Write(wxS("Type"), static_cast<long>(type));

configObject.SetPath(wxS("Label"));
myLabel.Save(configObject);
configObject.SetPath(wxS("../StartMult"));
myStartMult.Save(configObject);
configObject.SetPath(wxS("../EndMult"));
myEndMult.Save(configObject);
configObject.SetPath(wxS(".."));

glSelfEdge::Save(configObject);
