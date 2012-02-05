//~~ void Save(wxConfigBase& configObject) [glNode] ~~

glFloatingItem::Save(configObject);

configObject.Write(wxS("ID"), id);
