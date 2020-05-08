//~~ void Save(wxConfigBase& configObject) [glNode] ~~

glFloatingItem::Save(configObject);

configObject.Write(wxS("ID"), id);
configObject.Write(wxS("metaData"), metaData);
configObject.Write(wxS("htmlLink"), htmlLink);
