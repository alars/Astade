//~~ void Load(wxConfigBase& configObject) [glNode] ~~

glFloatingItem::Load(configObject);

configObject.Read(wxS("ID"), &id);
configObject.Read(wxS("metaData"), &metaData);
configObject.Read(wxS("htmlLink"), &htmlLink);

if (!htmlLink.empty())
    AddMenuFunction(wxS("open link"), wxCommandEventHandler(glNode::openLink));
