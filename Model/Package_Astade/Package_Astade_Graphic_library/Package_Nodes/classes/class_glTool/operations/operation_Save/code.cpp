//~~ void Save(wxConfigBase& configObject) [glTool] ~~

glNode::Save(configObject);
configObject.Write("ClassName","tool");
configObject.Write("Label",myLabel);

int associationCount = 0;
int specialisationCount = 0;

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); ++it)
    if (&(*it)->GetStartNode() == this)
    {
        glAssociation* anAssociation = dynamic_cast<glAssociation*>(*it);
        
        if (anAssociation)
        {
            wxString aString;
            aString.Printf("Association%03d", ++associationCount);
            configObject.Write(aString, anAssociation->GetEndNode().id);
        }
        
        glSpecialize* aSpecialisation = dynamic_cast<glSpecialize*>(*it);
        
        if (aSpecialisation)
        {
            wxString aString;
            aString.Printf("Superclass%03d", ++specialisationCount);
            configObject.Write(aString, aSpecialisation->GetEndNode().id);
        }
    }
