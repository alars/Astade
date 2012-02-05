//~~ void Load(wxConfigBase& configObject) [glSelfRelation] ~~

long aType;
configObject.Read(wxS("Type"), &aType);
type = static_cast<relationType>(aType);

configObject.SetPath(wxS("Label"));
myLabel.Load(configObject);
configObject.SetPath(wxS("../StartMult"));
myStartMult.Load(configObject);
configObject.SetPath(wxS("../EndMult"));
myEndMult.Load(configObject);
configObject.SetPath(wxS(".."));
glSelfEdge::Load(configObject);
