configObject.Write("Type",static_cast<long>(type));

configObject.SetPath("Label");
myLabel.Save(configObject);
configObject.SetPath("../StartMult");
myStartMult.Save(configObject);
configObject.SetPath("../EndMult");
myEndMult.Save(configObject);
configObject.SetPath("..");
