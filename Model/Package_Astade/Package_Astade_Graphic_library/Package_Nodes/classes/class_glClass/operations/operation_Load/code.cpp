//~~ void Load(wxConfigBase& configObject) [glClass] ~~

configObject.Read(wxS("Active"), &active);
configObject.Read(wxS("Label"), &myLabel);
myLabel.Trim(false);
myLabel.Trim(true);
myLabel.Replace(wxS("\t"), wxS(" "));
myLabel.Replace(wxS("\n"), wxS(" "));
myLabel.Replace(wxS("  "), wxS(" "));

glNode::Load(configObject);
