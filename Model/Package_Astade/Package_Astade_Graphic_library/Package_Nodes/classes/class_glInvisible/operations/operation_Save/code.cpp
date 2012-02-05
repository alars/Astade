//~~ void Save(wxConfigBase& configObject) [glInvisible] ~~

glNode::Save(configObject);
configObject.Write(wxS("ClassName"), wxS("invisible node"));
