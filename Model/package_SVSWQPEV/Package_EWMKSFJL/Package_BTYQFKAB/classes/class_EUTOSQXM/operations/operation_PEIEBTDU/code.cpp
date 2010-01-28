int count = 1;
wxString useName;

useName.Printf("Relation%03d",count);
while (configObject.Exists(useName))
{
    int UseID;
    configObject.Read(useName,&UseID);
    
    glNode* partnerNode = glNode::getNodeById(UseID);
    
    if (partnerNode)
    {
        glRelation* aRelation = new glRelation(myParent, *this, *partnerNode);
        configObject.SetPath(useName);
        aRelation->Load(configObject);
        configObject.SetPath("..");
    }
    
    useName.Printf("Relation%03d",++count);
}

count = 1;
useName.Printf("SelfRelation%03d",count);
while (configObject.Exists(useName))
{
    glSelfRelation* aRelation = new glSelfRelation(*myParent, *this, glVector());
    configObject.SetPath(useName);
    aRelation->Load(configObject);
    configObject.SetPath("..");
    
    useName.Printf("SelfRelation%03d",++count);
}
