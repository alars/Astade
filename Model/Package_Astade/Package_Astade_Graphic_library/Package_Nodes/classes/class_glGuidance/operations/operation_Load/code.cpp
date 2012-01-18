//~~ void Load(wxConfigBase& configObject) [glGuidance] ~~
configObject.Read("Label",&myLabel);
myLabel.Trim(false);
myLabel.Trim(true);
myLabel.Replace("\t"," ");
myLabel.Replace("\n"," ");
myLabel.Replace("  "," ");

glNode::Load(configObject);
