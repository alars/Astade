//~~ void Save(wxConfigBase& configObject) [glClass] ~~

glNode::Save(configObject);
configObject.Write(wxS("Label"), myLabel);
configObject.Write(wxS("ClassName"), wxS("class"));
configObject.Write(wxS("Active"), active);

int relationCount = 0;

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); ++it)
{
    if (&(*it)->GetStartNode() == this)
    {
        glRelation* aRelation = dynamic_cast<glRelation*>(*it);
       
        if (aRelation)
        {
            wxString aString;
            aString.Printf(wxS("Relation%03d"), ++relationCount);
            configObject.Write(aString,aRelation->GetEndNode().id);
            configObject.SetPath(aString);
            aRelation->Save(configObject);
            configObject.SetPath(wxS(".."));
        }
    }
}

int selfrelationCount = 0;
for (std::set<glSelfEdge*>::iterator it = mySelfEdges.begin(); it != mySelfEdges.end(); ++it)
{
    glSelfRelation* aSelfRelation = dynamic_cast<glSelfRelation*>(*it);
    
    if (aSelfRelation)
    {
        wxString aString;
        aString.Printf(wxS("SelfRelation%03d"), ++selfrelationCount);
        configObject.SetPath(aString);
        aSelfRelation->Save(configObject);
        configObject.SetPath(wxS(".."));
    }
}
