long aType;

configObject.Read("Type",&aType);
type = static_cast<relationType>(aType);

configObject.SetPath("Label");
myLabel.Load(configObject);
configObject.SetPath("../StartMult");
myStartMult.Load(configObject);
configObject.SetPath("../EndMult");
myEndMult.Load(configObject);
configObject.SetPath("..");
glSelfEdge::Load(configObject);
