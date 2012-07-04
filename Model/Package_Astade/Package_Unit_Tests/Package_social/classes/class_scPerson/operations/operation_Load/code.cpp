//~~ void Load(wxConfigBase& configObject) [scPerson] ~~

configObject.Read(wxS("Label"), &myLabel);
myLabel.Trim(false);
myLabel.Trim(true);
myLabel.Replace(wxS("\t"), wxS(" "));
myLabel.Replace(wxS("\n"), wxS(" "));
myLabel.Replace(wxS("  "), wxS(" "));

configObject.Read(wxS("Male"), &male);
configObject.Read(wxS("Child"), &child);
glNode::Load(configObject);
