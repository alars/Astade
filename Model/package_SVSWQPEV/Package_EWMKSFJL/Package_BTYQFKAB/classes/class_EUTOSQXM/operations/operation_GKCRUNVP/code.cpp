glNode::Save(configObject);
configObject.Write("Label",myLabel);
configObject.Write("ClassName","class");
configObject.Write("Active",active);

int relationCount = 0;

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); it++)
{
    if (&(*it)->GetStartNode() == this)
    {
        glRelation* aRelation = dynamic_cast<glRelation*>(*it);
       
        if (aRelation)
        {
            wxString aString;
            aString.Printf("Relation%03d",++relationCount);
            configObject.Write(aString,aRelation->GetEndNode().id);
            configObject.SetPath(aString);
            aRelation->Save(configObject);
            configObject.SetPath("..");
        }
    }
}
