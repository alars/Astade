glNode::Save(configObject);
configObject.Write("Label",myLabel);
configObject.Write("ClassName","note");

int attachCount = 0;

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); it++)
    if (&(*it)->GetStartNode() == this)
    {
        glAttach* aAttach = dynamic_cast<glAttach*>(*it);
        
        if (aAttach)
        {
            wxString aString;
            aString.Printf("Attach%03d",++attachCount);
            configObject.Write(aString,aAttach->GetEndNode().id);
        }
    }
