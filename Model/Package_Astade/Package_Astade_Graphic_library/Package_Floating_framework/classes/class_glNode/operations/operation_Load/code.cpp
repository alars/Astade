//~~ void Load(wxConfigBase& configObject) [glNode] ~~

glFloatingItem::Load(configObject);

configObject.Read(wxS("ID"), &id);
