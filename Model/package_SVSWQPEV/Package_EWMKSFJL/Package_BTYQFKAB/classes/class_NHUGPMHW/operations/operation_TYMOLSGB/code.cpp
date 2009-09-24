glNode::Save(configObject);
configObject.Write("Label",myLabel);
configObject.Write("ClassName","state");

int transCount = 0;

for (std::set<glEdge*>::iterator it = myEdges.begin(); it != myEdges.end(); it++)
    if (&(*it)->GetStartNode() == this)
    {

        glTransition* aTransition = dynamic_cast<glTransition*>(*it);
       
        if (aTransition)
        {
            wxString aString;
            aString.Printf("Transition%03d",++transCount);
            configObject.Write(aString,aTransition->GetEndNode().id);
        }

    }
