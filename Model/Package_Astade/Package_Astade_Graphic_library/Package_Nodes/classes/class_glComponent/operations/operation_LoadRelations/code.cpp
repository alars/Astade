//~~ void LoadRelations(wxConfigBase& configObject) [glComponent] ~~

int count = 1;

wxString useName;
useName.Printf(wxS("InterfaceUse%03d"), count);

while (configObject.Exists(useName))
{
    int UseID;
    configObject.Read(useName, &UseID);
    
    glNode* partnerNode = glNode::getNodeById(UseID);
    
    if (partnerNode)
        new glUseInterface(myParent, *this, *partnerNode);
    
    count++;
    useName.Printf(wxS("InterfaceUse%03d"), count);
}

count = 1;
wxString provideName;
provideName.Printf(wxS("InterfaceProvide%03d"), count);

while (configObject.Exists(provideName))
{
    int ProvideID;
    configObject.Read(provideName, &ProvideID);
    
    glNode* partnerNode = glNode::getNodeById(ProvideID);
    
    if (partnerNode)
        new glProvideInterface(myParent, *this, *partnerNode);
    
    count++;
    provideName.Printf(wxS("InterfaceProvide%03d"), count);
}

count = 1;
useName.Printf(wxS("ComponentUse%03d"), count);

while (configObject.Exists(useName))
{
    int ProvideID;
    configObject.Read(useName, &ProvideID);
    
    glNode* partnerNode = glNode::getNodeById(ProvideID);
    
    if (partnerNode)
        new glIncludeExtend(myParent, *this, *partnerNode, wxS("\xab" "use" "\xbb"));

    count++;
    useName.Printf(wxS("ComponentUse%03d"), count);
}
