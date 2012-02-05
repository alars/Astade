//~~ void Save(wxConfigBase& configObject) [glEndNode] ~~

glNode::Save(configObject);
configObject.Write(wxS("ClassName"), wxS("end node"));
