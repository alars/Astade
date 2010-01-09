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