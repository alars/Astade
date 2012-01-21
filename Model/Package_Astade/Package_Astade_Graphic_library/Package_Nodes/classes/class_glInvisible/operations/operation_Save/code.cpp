//~~ void Save(wxConfigBase& configObject) [glInvisible] ~~

glNode::Save(configObject);
configObject.Write("ClassName", "invisible node");
