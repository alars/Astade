//~~ void Save(wxConfigBase& configObject) [glStartNode] ~~
glNode::Save(configObject);
configObject.Write("ClassName","start node");

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
            configObject.SetPath(aString);
            aTransition->Save(configObject);
            configObject.SetPath("..");
        }

    }
