//~~ void LoadRelations(wxConfigBase& configObject) [glComponent] ~~

int count = 1;

wxString useName;
useName.Printf(wxS("CreateArtefact%03d"), count);

while (configObject.Exists(useName))
{
    int UseID;
    configObject.Read(useName, &UseID);
    
    glNode* partnerNode = glNode::getNodeById(UseID);
    
    if (partnerNode)
        new glCreateArtefact(myParent, *this, *partnerNode);
    
    count++;
    useName.Printf(wxS("CreateArtefact%03d"), count);
}