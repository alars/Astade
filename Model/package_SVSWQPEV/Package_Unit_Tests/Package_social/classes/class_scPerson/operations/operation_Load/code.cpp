configObject.Read("Label",&myLabel);
myLabel.Trim(false);
myLabel.Trim(true);
myLabel.Replace("\t"," ");
myLabel.Replace("\n"," ");
myLabel.Replace("  "," ");

configObject.Read("Male",&male);
configObject.Read("Child",&child);
glNode::Load(configObject);
